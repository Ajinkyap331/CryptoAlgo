#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool areCoprime(int a, int b)
{
    return __gcd(a, b) == 1;
}

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i)
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

int main()
{
    int p;
    cout << "Enter a prime number (p): ";
    cin >> p;
    while (!isPrime(p))
    {
        cout << "Not a Prime Number" << endl;
        cout << "Enter a prime number (p): ";
        cin >> p;
    }

    int q;
    cout << "Enter a prime number (q): ";
    cin >> q;
    while (!isPrime(q))
    {
        cout << "Not a Prime Number" << endl;
        cout << "Enter a prime number (q): ";
        cin >> q;
    }

    if (p == q)
    {
        cout << "p and q should be different prime numbers." << endl;
        return 1;
    }

    int N = p * q;

    int phi = (p - 1) * (q - 1);
    cout << "Phi: " << phi << endl;

    int e;
    cout << "Enter a number (d): ";
    cin >> e;
    while (!areCoprime(e, phi) || e <= 1 || e >= phi)
    {
        cout << "Should not be a Multiple of Phi" << endl;
        cout << "Enter a number (e): ";
        cin >> e;
    }

    int d = 0;
    while ((d * e) % phi != 1)
    {
        d += 1;
    }
    cout << "d: " << d << endl;

    int PT;
    cout << "Enter Plain Text: ";
    cin >> PT;

    int CT = modPow(PT, e, N);
    cout << "Encrypted Text: " << CT << endl;

    int DT = modPow(CT, d, N);
    cout << "Decrypted Text: " << DT << endl;

    return 0;
}
