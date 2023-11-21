#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Function to calculate the SHA-1 hash of a message string
string sha1(const string& message) {
    // Initialize the SHA-1 context
    unsigned char hash[20];
    unsigned int h0, h1, h2, h3, h4;
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    h4 = 0xC3D2E1F0;

    // Append padding to the message string
    string paddedMessage = message;
    paddedMessage += static_cast<char>(0x80);
    while ((paddedMessage.size() * 8) % 512 != 448) {
        paddedMessage += static_cast<char>(0x00);
    }

    // Append the original message length
    unsigned long long messageLength = message.size() * 8;
    for (int i = 7; i >= 0; i--) {
        paddedMessage += static_cast<char>((messageLength >> (i * 8)) & 0xFF);
    }

    // Process the padded message
    for (size_t i = 0; i < paddedMessage.size(); i += 64) {
        unsigned int w[80];

        for (int j = 0; j < 16; j++) {
            w[j] = (paddedMessage[i + j * 4] << 24) | (paddedMessage[i + j * 4 + 1] << 16) | (paddedMessage[i + j * 4 + 2] << 8) | (paddedMessage[i + j * 4 + 3]);
        }
        for (int j = 16; j < 80; j++) {
            w[j] = (w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16]);
            w[j] = (w[j] << 1) | (w[j] >> 31);
        }

        unsigned int a = h0;
        unsigned int b = h1;
        unsigned int c = h2;
        unsigned int d = h3;
        unsigned int e = h4;

        for (int j = 0; j < 80; j++) {
            unsigned int f, k;
            if (j < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } else if (j < 40) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if (j < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            unsigned int temp = ((a << 5) | (a >> 27)) + f + e + k + w[j];
            e = d;
            d = c;
            c = (b << 30) | (b >> 2);
            b = a;
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    // Combine the hash values
    memcpy(hash, &h0, 4);
    memcpy(hash + 4, &h1, 4);
    memcpy(hash + 8, &h2, 4);
    memcpy(hash + 12, &h3, 4);
    memcpy(hash + 16, &h4, 4);

    // Convert the hash to a string of hexadecimal characters
    string result;
    for (int i = 0; i < 20; i++) {
        result += "0123456789ABCDEF"[((hash[i] >> 4) & 0xF)];
        result += "0123456789ABCDEF"[((hash[i]) & 0xF)];
    }

    return result;
}

int main() {
    // User input for the message string
    string message;
    cout << "Enter the message to be hashed: ";
    getline(cin, message);

    // Calculate SHA-1 hash
    string hash = sha1(message);

    // Display the calculated SHA-1 hash
    cout << "\nSHA-1 Hash of the message: " << hash << endl;

    // Demonstrate using the hash value (for example, here just displaying the first 8 characters)
    cout << "\nFirst 8 characters of the hash: " << hash.substr(0, 8) << endl;

    string m1;
    cout << "\nEnter the similar message to be hashed: ";
    getline(cin, m1);

    string hash1 = sha1(m1);

    // Display the calculated SHA-1 hash
    cout << "\nSHA-1 Hash of the message: " << hash1 << endl;

    cout<<"\nHence It is verified that a small change in input will drastically change the output\n"<<endl;

    return 0;
}