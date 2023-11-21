#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int gen_key(int q)
{
    int key;
    do
    {
        cout << "Enter a private key (should be a large random number): ";
        cin >> key;
    } while (gcd(q, key) != 1);
    return key;
}

int power(int a, int b, int c)
{
    int x = 1;
    int y = a;
    while (b > 0)
    {
        if (b % 2 != 0)
        {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b = b / 2;
    }
    return x % c;
}

pair<vector<int>, int> encrypt(const string &msg, int q, int h, int g)
{
    vector<int> en_msg;
    int k = gen_key(q);
    int s = power(h, k, q);
    int p = power(g, k, q);
    for (char ch : msg)
    {
        en_msg.push_back(s * int(ch));
    }
    cout << "g^k used: " << p << endl;
    cout << "g^ak used: " << s << endl;
    return make_pair(en_msg, p);
}

string decrypt(const vector<int> &en_msg, int p, int key, int q)
{
    string dr_msg;
    int h = power(p, key, q);
    for (int val : en_msg)
    {
        dr_msg += char(val / h);
    }
    return dr_msg;
}

int main()
{
    string msg;
    cout << "Enter the message to be encrypted: ";
    cin >> msg;

    int q, g;
    cout << "Enter a large prime number q: ";
    cin >> q;
    cout << "Enter a primitive root g: ";
    cin >> g;

    int key = gen_key(q);
    int h = power(g, key, q);

    cout << "g used: " << g << endl;
    cout << "g^a used: " << h << endl;

    pair<vector<int>, int> encryption_result = encrypt(msg, q, h, g);
    vector<int> en_msg = encryption_result.first;
    int p = encryption_result.second;

    string dr_msg = decrypt(en_msg, p, key, q);
    cout << "Encrypted Message: ";
    for (int val : en_msg)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Decrypted Message: " << dr_msg << endl;

    return 0;
}