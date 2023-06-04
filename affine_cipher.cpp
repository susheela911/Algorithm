#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encrypt(const string& message, int a, int b) {
    string encryptedMessage;
    for (char ch : message) {
        if (isalpha(ch)) {
            char encryptedChar = (a * (toupper(ch) - 'A') + b) % 26 + 'A';
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += ch;
        }
    }
    return encryptedMessage;
}

string decrypt(const std::string& message, int a, int b) {
    
    int aInverse = -1;
    for (int i = 0; i < 26; ++i) {
        if ((a * i) % 26 == 1) {
            aInverse = i;
            break;
        }
    }

    if (aInverse == -1) {
        cout << "Invalid value of 'a'. It must be coprime with 26." << std::endl;
        return "";
    }

    string decryptedMessage;
    for (char ch : message) {
        if (isalpha(ch)) {
            char decryptedChar = (aInverse * (toupper(ch) - 'A' - b + 26)) % 26 + 'A';
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += ch;
        }
    }
    return decryptedMessage;
}

int main() {
    string message;
    int a, b;
    cout << "Enter the message: ";
    getline(std::cin, message);
    cout << "Enter the value of 'a': ";
    cin >> a;
    cout << "Enter the value of 'b': ";
    cin >> b;
    string encryptedMessage = encrypt(message, a, b);
    cout << "Encrypted message: " << encryptedMessage << std::endl;
    string decryptedMessage = decrypt(encryptedMessage, a, b);
    cout << "Decrypted message: " << decryptedMessage << std::endl;
    return 0;
}
