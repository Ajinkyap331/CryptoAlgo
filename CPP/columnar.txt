#include <iostream>
#include <vector>

using namespace std;

string encrypt(const string &text, int key)
{
    // Calculate the number of rows needed
    int num_rows = text.length() / key + (text.length() % key > 0);

    // Create an empty grid
    vector<vector<char>> grid(num_rows, vector<char>(key, ' '));

    // Fill in the grid with characters from the text
    int index = 0;
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < key; ++j)
        {
            if (index < text.length())
            {
                grid[i][j] = text[index];
                index += 1;
            }
        }
    }

    // Read the grid column by column
    string result = "";
    for (int j = 0; j < key; ++j)
    {
        for (int i = 0; i < num_rows; ++i)
        {
            result += grid[i][j];
        }
    }

    cout << result << endl;

    return result;
}

string decrypt(const string &text, int key)
{
    // Calculate the number of rows needed
    int num_rows = text.length() / key + (text.length() % key > 0);

    // Calculate the number of incomplete rows
    int incomplete_rows = key - (text.length() % key);

    // Create an empty grid
    vector<vector<char>> grid(num_rows, vector<char>(key, ' '));

    // Fill in the grid with characters from the text
    int index = 0;
    for (int j = 0; j < key; ++j)
    {
        for (int i = 0; i < num_rows; ++i)
        {
            if (i == incomplete_rows && j >= text.length() % key)
            {
                grid[i][j] = ' ';
            }
            else
            {
                grid[i][j] = text[index];
                index += 1;
            }
        }
    }

    // Read the grid row by row
    string result = "";
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < key; ++j)
        {
            if (grid[i][j] != ' ')
            {
                result += grid[i][j];
            }
        }
    }

    return result;
}

int main()
{
    string plaintext = "COLUMNARTRANSPOSITION";
    int key = 5;

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decrypted_text = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
