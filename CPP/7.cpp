#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPrime(int n)
{
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int modPow(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

pair<int, int> encrypt(int e1, int e2, int p)
{
    srand(time(0));
    int r = rand() % (p - 1) + 1;
    cout << "Random number r is : " << r << endl;
    int c1 = modPow(e1, r, p);
    int m;
    do
    {
        cout << "Enter Message m : ";
        cin >> m;
    } while (!(m < p));
    int c2 = (m * modPow(e2, r, p)) % p;
    pair<int, int> ct = make_pair(c1, c2);
    cout << "Cipher text is : (" << ct.first << ", " << ct.second << ")" << endl;
    return ct;
}

void decrypt(int c1, int c2, int p, int d)
{
    int pt = (c2 * modPow(modPow(c1, p - 1 - d, p), 1, p)) % p;
    cout << "Decrypted message is : " << pt << endl;
}

int main()
{
    int p = 0;
    while (!isPrime(p))
    {
        cout << "Select a Prime Number p : ";
        cin >> p;
    }
    int d;
    cout << "Enter private key d : ";
    cin >> d;

    int e1;
    do
    {
        cout << "Enter e1 : ";
        cin >> e1;
    } while (!(1 < e1 && e1 < p - 1));

    int e2 = modPow(e1, d, p);
    cout << "Public key is : (" << e1 << ", " << e2 << ", " << p << ")" << endl;
    cout << "Private key is : " << d << endl;

    pair<int, int> ct = encrypt(e1, e2, p);

    decrypt(ct.first, ct.second, p, d);

    return 0;
}
