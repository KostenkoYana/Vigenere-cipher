#include <iostream>
#include <string>
using namespace std;

string vigenereCipher(const string& text, const string& key, bool encrypt) {
    string result = "";
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        int shift = key[keyIndex] - ' ';
        if (!encrypt) {
            shift = -shift;
        }
                result += char((c - ' ' + shift + 95) % 95 + ' ');
        keyIndex = (keyIndex + 1) % keyLength;
    }
    return result;
}

int main() {
    string text, key;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the key: ";
    getline(cin, key);
    
    string encryptedText = vigenereCipher(text, key, true);
    string decryptedText = vigenereCipher(encryptedText, key, false);

    cout << "Original Text: " << text << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
