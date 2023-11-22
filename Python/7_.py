# Python program to illustrate ElGamal encryption

# Very Large Number q
# q = Number between 10^20 and 10^50
# g = Number between 2 and q
# key = Number between 10^20 and q which is coprime with q
# h = g^key mod q



import random, math


def gcd(a, b):
    if a < b:
        return gcd(b, a)
    elif a % b == 0:
        return b
    else:
        return gcd(b, a % b)
	

def power(a, b, c):
    x = 1
    y = a

    while b > 0:
        if b % 2 != 0:
            x = (x * y) % c
        y = (y * y) % c
        b = int(b / 2)

    return x % c


def gen_key(q):

	key = random.randint(pow(10, 20), q)
	while math.gcd(q, key) != 1:
		key = random.randint(pow(10, 20), q)
	return key

def encrypt(msg, q, h, g):

	en_msg = list(msg)

	k = gen_key(q)  # Private key for sender
	s = pow(h, k, q)
	p = pow(g, k, q)

	print("g^k used : ", p)
	print("g^ak used : ", s)

	for i in range(0, len(en_msg)):
		en_msg[i] = s * ord(en_msg[i])

	print("en_msg : ", en_msg)

	return en_msg, p


def decrypt(en_msg, p, key, q):

	dr_msg = []
	h = pow(p, key, q)
	for i in range(0, len(en_msg)):
		dr_msg.append(chr(int(en_msg[i]/h)))

	return dr_msg


def main():

	msg = 'Ajinkya'
	print("Original Message :", msg)

	q = random.randint(pow(10, 20), pow(10, 50))
	g = random.randint(2, q)
	
	print("q used : ", q)
	print("g used : ", g)

	key = gen_key(q)  
	print("Private Key :", key)

	h = pow(g, key, q)

	print("g^a used : ", h)

	en_msg, p = encrypt(msg, q, h, g)
	dr_msg = decrypt(en_msg, p, key, q)
	dmsg = ''.join(dr_msg)
	print("Decrypted Message :", dmsg)


if __name__ == '__main__':
	main()
