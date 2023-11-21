def generate_key(plaintext, keyword):
    n = len(plaintext)
    k = len(keyword)
    count = 1
    for i in range(k, n):
        if i % k == 0 and i > k:
            count += 1
        c = chr(ord('A') + (ord(keyword[i - k]) - ord('A') + k * count) % 26)
        keyword += c
    print("New Key:", keyword)
    return keyword


def encrypt(plaintext, keyword):
    ciphertext = ""
    n = len(plaintext)
    for i in range(n):
        x = chr(((ord(plaintext[i]) + ord(keyword[i])) % 26) + ord('A'))
        ciphertext += x

    for i in range(n):
        ciphertext = ciphertext[:i] + chr(((ord(ciphertext[i]) - ord('A') + ord(
            keyword[i]) - ord('A')) % 26) + ord('A')) + ciphertext[i + 1:]

    return ciphertext


def decrypt(ciphertext, keyword):
    decrypted_text = ""
    n = len(ciphertext)
    for i in range(n):
        x = (ord(ciphertext[i]) - ord(keyword[i]) + 26) % 26
        x += ord('A')
        decrypted_text += chr(x)

    for i in range(n):
        decrypted_text = decrypted_text[:i] + chr(((ord(decrypted_text[i]) - ord(
            'A') - ord(keyword[i]) + ord('A')) % 26) + ord('A')) + decrypted_text[i + 1:]

    return decrypted_text


plaintext = "HELLOWORLD"
keyword = "KEY"
key = generate_key(plaintext, keyword)
ciphertext = encrypt(plaintext, key)

print("Ciphertext:", ciphertext)
print("Original/Decrypted Text:", decrypt(ciphertext, key))
