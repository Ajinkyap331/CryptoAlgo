def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**(1/2)) + 1):
        if n % i == 0:
            return False
    return True


def main():
    p = int(input("Enter a prime number (p): "))
    while not isPrime(p):
        print("Not a Prime Number")
        p = int(input("Enter a prime number (p): "))
    
    q = int(input("Enter a prime number (q): "))
    while not isPrime(q):
        print("Not a Prime Number")
        q = int(input("Enter a prime number (q): "))

    N = p * q

    phi = (p - 1) * (q - 1)
    print("Phi: ", phi)

    e = int(input("Enter a number (d): "))
    while (phi % e == 0):
        print("Should not be a Multiple of Phi")
        e = int(input("Enter a number (d): "))

    d = 0 
    while (d * e) % phi != 1:
        d += 1
    print("d: ", d)

    PT = int(input("Enter Plain Text: "))

    CT = pow(PT, e, N)
    print("Encrypted Text: ", CT)

    DT = pow(CT, d, N)
    print("Decrypted Text: ", DT)

main()