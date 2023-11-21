#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

unordered_map<char, char> generate_monoalphabetic_key()
{
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<char> shuffled_alphabet = alphabet;
    random_shuffle(shuffled_alphabet.begin(), shuffled_alphabet.end());

    unordered_map<char, char> key;
    for (size_t i = 0; i < alphabet.size(); ++i)
    {
        key[alphabet[i]] = shuffled_alphabet[i];
    }

    for (const auto &entry : key)
    {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return key;
}

string monoalphabetic_cipher(const string &text, const unordered_map<char, char> &key)
{
    string result = "";
    for (char ch : text)
    {
        if (isalpha(ch))
        {
            bool is_upper = isupper(ch);
            char substituted_char = key.at(toupper(ch));

            substituted_char = is_upper ? toupper(substituted_char) : tolower(substituted_char);

            result += substituted_char;
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

string encrypt_monoalphabetic(const string &plaintext, const unordered_map<char, char> &key)
{
    return monoalphabetic_cipher(plaintext, key);
}

string decrypt_monoalphabetic(const string &ciphertext, const unordered_map<char, char> &key)
{
    unordered_map<char, char> reversed_key;
    for (const auto &entry : key)
    {
        reversed_key[entry.second] = entry.first;
    }
    return monoalphabetic_cipher(ciphertext, reversed_key);
}

int main()
{
    srand(time(0));

    string plaintext = "Hello, World!";
    cout << "Plaintext: " << plaintext << endl;

    unordered_map<char, char> key = generate_monoalphabetic_key();

    string ciphertext = encrypt_monoalphabetic(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_text = decrypt_monoalphabetic(ciphertext, key);
    cout << "Decrypted: " << decrypted_text << endl;

    return 0;
}
