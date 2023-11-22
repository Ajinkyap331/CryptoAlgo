# Prime Number P
# Private Key D
# Second Public Key E1
# Third Public Key E2 = E1^D mod P
# Public Key = E1, E2, P

# Encryption
# Random Number R
# Cipher Text C1 = E1^R mod P
# Cipher Text C2 = (M * E2^R) mod P
# Cipher Text = C1, C2

# Decryption
# Plain Text = (C2 * C1^(P - 1 - D)) mod P

import random

def isPrime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def encrypt(e1, e2, p):
    r = random.randint(1, p - 1)
    print("Random number r is : ", r)
    c1 = pow(e1, r) % p
    m = int(input("Enter Message m : "))
    while not m < p:
        m = int(input("Enter Message m : "))
    c2 = (m * pow(e2, r)) % p
    ct = (c1, c2)
    print("Cipher text is : ", ct)
    return ct

def decrypt(c1, c2, p, d):
    pt = (c2 * pow(c1, p - 1 - d)) % p
    print(pt)

def main():
    p = 0
    while not isPrime(p):
        p = int(input("Select a Prime Number p : "))
    d = int(input("Enter private key d : "))
    e1 = int(input("Enter e1 : "))
    while not e1 < p - 1 and e1 > 1:
        print("e1 must be less than p - 1 and greater than 1")
        e1 = int(input("Enter e1 : "))
    e2 = pow(e1, d, p)
    print("Public key is : ", e1, e2, p)
    print("Private key is : ", d)

    c1, c2 = encrypt(e1, e2, p)

    decrypt(c1, c2, p, d)

main()
