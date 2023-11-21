
class Alice:
    def __init__(self, p, q):
        self.p = p
        self.q = q
        self.a = 0

    def AliceEnc(self):
        self.a = int(input("Enter a random number (a): "))
        A = (self.q**self.a) % self.p
        print("Alice Sends Over Public Chanel: ", A)
        return A
    
    def AliceDec(self, B):
        k1 = (B**self.a) % self.p
        print("Alice Computes: ", k1)
        return k1
    
class Bob:
    def __init__(self, p, q):
        self.p = p
        self.q = q
        self.b = 0

    def BobEnc(self):
        self.b = int(input("Enter a random number (b): "))
        B = (self.q**self.b) % self.p
        print("Bob Sends Over Public Chanel: ", B)
        return B
    
    def BobDec(self, A):
        k2 = (A**self.b) % self.p
        print("Bob Computes: ", k2)
        return k2


def isPrimitive(p, q):
    vals = []
    for i in range(1, p):
        vals.append((q**i) % p)
    if len(set(vals)) != p - 1 and not all(i in vals for i in range(1, p - 1)):
        return False
    else: return True

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**(1/2)) + 1):
        if n % i == 0:
            return False
    return True


def main():
    # Public Keys
    p = int(input("Enter a prime number (p): "))
    while not isPrime(p):
        print("Not a Prime Number")
        p = int(input("Enter a prime number (p): "))
    
    
    q = int(input("Enter a primitive root of p (q): "))
    while not isPrimitive(p, q):
        print("Invalid Input")
        q = int(input("Enter a primitive root of p (q): "))


    a = Alice(p,q)
    b = Bob(p,q)

    A = a.AliceEnc()
    B = b.BobEnc()

    k1 = a.AliceDec(B)
    k2 = b.BobDec(A)

    if k1 == k2:
        print("Key Exchange Successful")
    else:
        print("Key Exchange Unsuccessful")


main()