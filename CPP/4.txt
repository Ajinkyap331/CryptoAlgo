#include <iostream>
#include <cmath>

using namespace std;

class Alice
{
private:
    int p;
    int q;
    int a;

public:
    Alice(int p, int q) : p(p), q(q), a(0) {}

    int AliceEnc()
    {
        cout << "Enter a random number (a): ";
        cin >> a;
        int A = static_cast<int>(pow(q, a)) % p;
        cout << "Alice Sends Over Public Channel: " << A << endl;
        return A;
    }

    int AliceDec(int B)
    {
        int k1 = static_cast<int>(pow(B, a)) % p;
        cout << "Alice Computes: " << k1 << endl;
        return k1;
    }
};

class Bob
{
private:
    int p;
    int q;
    int b;

public:
    Bob(int p, int q) : p(p), q(q), b(0) {}

    int BobEnc()
    {
        cout << "Enter a random number (b): ";
        cin >> b;
        int B = static_cast<int>(pow(q, b)) % p;
        cout << "Bob Sends Over Public Channel: " << B << endl;
        return B;
    }

    int BobDec(int A)
    {
        int k2 = static_cast<int>(pow(A, b)) % p;
        cout << "Bob Computes: " << k2 << endl;
        return k2;
    }
};

bool isPrimitive(int p, int q)
{
    for (int i = 1; i < p; ++i)
    {
        if (static_cast<int>(pow(q, i)) % p == 0)
        {
            return false;
        }
    }
    return true;
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
    cout << "Enter a primitive root of p (q): ";
    cin >> q;
    while (!isPrimitive(p, q))
    {
        cout << "Invalid Input" << endl;
        cout << "Enter a primitive root of p (q): ";
        cin >> q;
    }

    Alice a(p, q);
    Bob b(p, q);

    int A = a.AliceEnc();
    int B = b.BobEnc();

    int k1 = a.AliceDec(B);
    int k2 = b.BobDec(A);

    if (k1 == k2)
    {
        cout << "Key Exchange Successful" << endl;
    }
    else
    {
        cout << "Key Exchange Unsuccessful" << endl;
    }

    return 0;
}
