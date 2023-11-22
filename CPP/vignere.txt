#include <iostream>
#include <string>

using namespace std;

string generate_vigenere_key(const string &keyword, size_t text_length)
{
    string repeated_keyword = "";
    for (size_t i = 0; i < text_length; ++i)
    {
        repeated_keyword += keyword[i % keyword.length()];
    }

    cout << repeated_keyword << endl;

    return repeated_keyword;
}

string vigenere_cipher(const string &text, const string &keyword, bool encrypt = true)
{
    string result = "";
    for (size_t i = 0; i < text.length(); ++i)
    {
        char ch = text[i];
        if (isalpha(ch))
        {
            bool is_upper = isupper(ch);
            int ascii_code = static_cast<int>(ch);
            char keyword_char = keyword[i % keyword.length()];
            int keyword_code = static_cast<int>(toupper(keyword_char));
            int shift = keyword_code - static_cast<int>('A');
            int shifted_code = (encrypt ? (ascii_code - static_cast<int>('A' + (is_upper ? 0 : 32)) + shift + 26) : (ascii_code - static_cast<int>('A' + (is_upper ? 0 : 32)) - shift + 26)) % 26;
            char shifted_char = static_cast<char>(shifted_code + static_cast<int>('A' + (is_upper ? 0 : 32)));
            result += shifted_char;
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

string encrypt_vigenere(const string &plaintext, const string &keyword)
{
    return vigenere_cipher(plaintext, keyword);
}

string decrypt_vigenere(const string &ciphertext, const string &keyword)
{
    return vigenere_cipher(ciphertext, keyword, false);
}

int main()
{
    string plaintext = "hello, world";
    cout << "Plaintext: " << plaintext << endl;

    string keyword = "KEY";
    string repeated_keyword = generate_vigenere_key(keyword, plaintext.length());

    string ciphertext = encrypt_vigenere(plaintext, repeated_keyword);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_text = decrypt_vigenere(ciphertext, repeated_keyword);
    cout << "Decrypted: " << decrypted_text << endl;

    return 0;
}
