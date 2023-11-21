#include <bits/stdc++.h>
using namespace std;

string generateKey(string str, string key)
{
    int n = str.size();
    int k = key.size();
    int count = 1;
    for (int i = k; i < n; i++)
    {
        if (i % k == 0 && i > k)
            count++;
        char c = 'A' + ((key[i - k] - 'A' + k * count) % 26);
        key += c;
    }
    cout << "New Key : " << key << endl;
    return key;
}



string cipherText(string str, string key)
{
    string cipher_text;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        char x = 'A' + (str[i] + key[i]) % 26;

        cipher_text.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cipher_text[i] = 'A' + ((cipher_text[i] - 'A' + key[n - i - 1] - 'A') % 26);
    }

    return cipher_text;
}

string originalText(string cipher_text, string key)
{
    string orig_text;
    int n = cipher_text.size();
    for (int i = 0; i < n; i++)
    {
        char x = (cipher_text[i] - key[n - i - 1] + 26) % 26;
        x += 'A';
        orig_text.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        orig_text[i] = 'A' + (orig_text[i] - key[i] + 26) % 26;
    }
    return orig_text;
}

int main()
{
    string str = "HELLOWORLD";
    string keyword = "KEY";
    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);

    cout << "Ciphertext : " << cipher_text << "\n";
    cout << "Original/Decrypted Text : " << originalText(cipher_text, key);

    return 0;
}