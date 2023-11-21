#include <iostream>
#include <cctype>

using namespace std;

string caesar_cipher(const string &text, int shift)
{
    string result = "";
    for (char ch : text)
    {
        if (isalpha(ch))
        {
            bool is_upper = isupper(ch);
            int ascii_code = static_cast<int>(ch);
            int shifted_code = (ascii_code - static_cast<int>('A' + (is_upper ? 0 : 32)) + shift + 26) % 26;
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

string encrypt_caesar(const string &plaintext, int shift_amount)
{
    return caesar_cipher(plaintext, shift_amount);
}

string decrypt_caesar(const string &ciphertext, int shift_amount)
{
    return caesar_cipher(ciphertext, -shift_amount);
}

int main()
{
    string plaintext;
    cout << "Enter Plain Text: ";
    cin >> plaintext;

    int shift_amount;
    cout << "Enter Shift Amount: ";
    cin >> shift_amount;

    cout << "Plaintext: " << plaintext << endl;

    string ciphertext = encrypt_caesar(plaintext, shift_amount);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_text = decrypt_caesar(ciphertext, shift_amount);
    cout << "Decrypted: " << decrypted_text << endl;

    return 0;
}
