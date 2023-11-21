#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string plaintext;
    cout << "Enter the plain text: ";
    cin >> plaintext;

    int key;
    cout << "Enter the key: ";
    cin >> key;

    string ciphertext = "";
    vector<vector<char>> grid(key, vector<char>(plaintext.length(), ' '));

    bool forw = true;
    int j = 0;
    for (int i = 0; i < plaintext.size(); i++)
    {
        grid[j][i] = plaintext[i];
        if (forw)
        {
            ++j;
        }
        else
        {
            --j;
        }
        if (j == 0 && !forw)
        {
            forw = !forw;
        }
        else if (j == key - 1 && forw)
        {
            forw = !forw;
        }
    }

    for (const auto &row : grid)
    {
        for (char col : row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }

    for (const auto &row : grid)
    {
        for (char col : row)
        {
            if (col != ' ')
            {
                ciphertext += col;
            }
        }
    }

    cout << "Cipher Text: " << ciphertext << endl;

    grid = vector<vector<char>>(key, vector<char>(ciphertext.length(), '.'));

    forw = true;
    j = 0;
    for (int i = 0; i < ciphertext.size(); i++)
    {
        grid[j][i] = '*';
        if (forw)
        {
            ++j;
        }
        else
        {
            --j;
        }
        if (j == 0 && !forw)
        {
            forw = !forw;
        }
        else if (j == key - 1 && forw)
        {
            forw = !forw;
        }
    }

    int k = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '*')
            {
                grid[i][j] = ciphertext[k++];
            }
        }
    }

    cout << "Grid:" << endl;
    for (const auto &row : grid)
    {
        for (char col : row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }

    string decrypted_text = "";
    for (int i = 0; i < ciphertext.length(); ++i)
    {
        for (int j = 0; j < key; ++j)
        {
            if (grid[j][i] != '.')
            {
                decrypted_text += grid[j][i];
            }
        }
    }

    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
