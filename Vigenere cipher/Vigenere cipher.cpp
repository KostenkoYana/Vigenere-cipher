#include <iostream>
#include <string>
using namespace std;

string vigenereCipher(const string& text, const string& key, bool encrypt) {
    string result = "";
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            char keyChar = key[keyIndex % keyLength];
            char keyOffset = isupper(keyChar) ? 'A' : 'a';
            int shift = encrypt ? keyChar - keyOffset : keyOffset - keyChar;

            result += static_cast<char>((c - offset + shift + 26) % 26 + offset);
            keyIndex++;
        }
        else {
            result += c;
        }
    }

    return result;
}

int main() {
    string text, key;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the key: ";
    cin >> key;

    string encryptedText = vigenereCipher(text, key, true);
    string decryptedText = vigenereCipher(encryptedText, key, false);

    cout << "Original Text: " << text << endl;
    //cout << "Key: " << key << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
