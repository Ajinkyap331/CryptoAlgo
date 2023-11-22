# Columnar Transposition Cipher
def encrypt(text, key):
    # Calculate the number of rows needed
    num_rows = len(text) // key + int(len(text) % key > 0)


    # Create an empty grid
    grid = [[' ' for _ in range(key)] for _ in range(num_rows)]


    # Fill in the grid with characters from the text
    index = 0
    for i in range(num_rows):
        for j in range(key):
            if index < len(text):
                grid[i][j] = text[index]
                index += 1

    # Read the grid column by column
    result = ""
    for j in range(key):
        for i in range(num_rows):
            result += grid[i][j]

    print(result, grid)

    return result


def decrypt(text, key):
    # Calculate the number of rows needed
    num_rows = len(text) // key + int(len(text) % key > 0)

    # Calculate the number of incomplete rows
    incomplete_rows = key - (len(text) % key)

    # Create an empty grid
    grid = [[' ' for _ in range(key)] for _ in range(num_rows)]

    # Fill in the grid with characters from the text
    index = 0
    for j in range(key):
        for i in range(num_rows):
            if i == incomplete_rows and j >= len(text) % key:
                grid[i][j] = ' '
            else:
                grid[i][j] = text[index]
                index += 1

    # Read the grid row by row
    result = ""
    for i in range(num_rows):
        for j in range(key):
            if grid[i][j] != ' ':
                result += grid[i][j]

    return result


# Example usage
plaintext = "COLUMNARTRANSPOSITION"
key = 5

# Encrypt the plaintext
ciphertext = encrypt(plaintext, key)
print(f"Plaintext: {plaintext}")
print(f"Ciphertext: {ciphertext}")

# Decrypt the ciphertext
decrypted_text = decrypt(ciphertext, key)
print(f"Decrypted Text: {decrypted_text}")
