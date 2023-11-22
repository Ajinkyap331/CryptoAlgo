# Monoalphabetic
import random

def generate_monoalphabetic_key():
    alphabet = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    shuffled_alphabet = list(alphabet)
    random.shuffle(shuffled_alphabet)

    key = dict(zip(alphabet, shuffled_alphabet))
    print(key)
    return key


def monoalphabetic_cipher(text, key):
    result = ""
    for char in text:
        if char.isalpha():
            is_upper = char.isupper()

            substituted_char = key[char.upper()]

            substituted_char = substituted_char.upper() if is_upper else substituted_char.lower()

            result += substituted_char
        else:
            result += char

    return result

def encrypt_monoalphabetic(plaintext, key):
    return monoalphabetic_cipher(plaintext, key)

def decrypt_monoalphabetic(ciphertext, key):
    reversed_key = {value: key for key, value in key.items()}
    return monoalphabetic_cipher(ciphertext, reversed_key)


# Example usage
plaintext = "Hello, World!"
key = generate_monoalphabetic_key()
ciphertext = monoalphabetic_cipher(plaintext, key)
decypttext =  decrypt_monoalphabetic(ciphertext, key)

print(f"Plaintext: {plaintext}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {decypttext}")
