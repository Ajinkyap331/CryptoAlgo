# Polyalphabetic Substitution Cipher (Vigenere Cipher)
def generate_vigenere_key(keyword, text_length):
    # Repeat the keyword to match the length of the text
    repeated_keyword = ""

    for i in range(text_length):
        repeated_keyword += keyword[i % len(keyword)]

    print(repeated_keyword)

    return repeated_keyword


def vigenere_cipher(text, keyword, encrypt=True):
    result = ""
    for i, char in enumerate(text):
        if char.isalpha():
            is_upper = char.isupper()
            ascii_code = ord(char)
            keyword_char = keyword[i % len(keyword)]
            keyword_code = ord(keyword_char.upper())
            shift = keyword_code - ord('A')
            if encrypt:
                shifted_code = (
                    ascii_code - ord('A' if is_upper else 'a') + shift) % 26
            else:
                shifted_code = (
                    ascii_code - ord('A' if is_upper else 'a') - shift) % 26
            shifted_char = chr(shifted_code + ord('A' if is_upper else 'a'))
            result += shifted_char
        else:
            result += char

    return result

def encrypt_vigenere(plaintext, keyword):
    return vigenere_cipher(plaintext, keyword)

def decrypt_vigenere(ciphertext, keyword):
    return vigenere_cipher(ciphertext, keyword, encrypt=False)

# Example usage
plaintext = "Hello, World!"
keyword = "KEY"
ciphertext = vigenere_cipher(plaintext, generate_vigenere_key(keyword, len(plaintext)))

print(f"Plaintext: {plaintext}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {decrypt_vigenere(ciphertext, keyword)}")
