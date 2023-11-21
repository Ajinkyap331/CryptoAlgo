## Caesar
def caesar_cipher(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            is_upper = char.isupper()

            ascii_code = ord(char)

            shifted_code = (ascii_code - ord('A' if is_upper else 'a') + shift) % 26

            shifted_char = chr(shifted_code + ord('A' if is_upper else 'a'))

            result += shifted_char
        else:
            result += char

    return result

def encrypt_caesar(plaintext, shift_amount):
    return caesar_cipher(plaintext, shift_amount)

def decrypt_caesar(ciphertext, shift_amount):
    return caesar_cipher(ciphertext, -shift_amount)


# Example usage
plaintext = input("Enter Plain Text: ")
shift_amount = int(input("Enter Shift Amount: "))

print(f"Plaintext: {plaintext}")
ciphertext = encrypt_caesar(plaintext, shift_amount)
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {decrypt_caesar(ciphertext, shift_amount)}")
