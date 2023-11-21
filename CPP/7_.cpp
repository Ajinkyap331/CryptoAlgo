#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    else if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
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

int gen_key(int q)
{
    long long int key = rand() % (int)pow(10, 10) + q;
    while (gcd(q, key) != 1)
    {
        key = rand() % (int)pow(10, 10) + q;
    }
    return key;
}

vector<int> encrypt(const string &msg, int q, int h, int g)
{
    vector<int> en_msg(msg.length());

    int k = gen_key(q);
    int s = power(h, k, q);
    int p = power(g, k, q);

    cout << "g^k used : " << p << endl;
    cout << "g^ak used : " << s << endl;

    for (size_t i = 0; i < msg.length(); ++i)
    {
        en_msg[i] = s * int(msg[i]);
    }

    cout << "en_msg : ";
    for (int val : en_msg)
    {
        cout << val << " ";
    }
    cout << endl;

    return en_msg;
}

string decrypt(const vector<int> &en_msg, int p, int key, int q)
{
    string dr_msg;

    int h = power(p, key, q);
    for (int val : en_msg)
    {
        dr_msg.push_back(char(val / h));
    }

    return dr_msg;
}

int main()
{
    srand(time(0));

    string msg = "Ajinkya";
    cout << "Original Message: " << msg << endl;

    long long int q = rand() % (int)pow(10, 20) + pow(10, 10);
    long long int g = rand() % (q - 2) + 2;

    cout << "q used : " << q << endl;
    cout << "g used : " << g << endl;

    int key = gen_key(q);
    cout << "Private Key : " << key << endl;

    int h = power(g, key, q);
    cout << "g^a used : " << h << endl;

    vector<int> en_msg = encrypt(msg, q, h, g);
    string dr_msg = decrypt(en_msg, h, key, q);

    cout << "Decrypted Message : " << dr_msg << endl;

    return 0;
}
