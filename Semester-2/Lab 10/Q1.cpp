#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TextEncryptor {
private:
    string normalText;
    string encryptedText;
    string decryptedText;
    string fileName;

    string EncryptText(const string& text) {
        string encrypted = text;
        int length = text.length();
        for (int i = 0; i < length; i++) {
            encrypted[i] = text[i] + (i + 1);
        }
        return encrypted;
    }

    string DecryptText(const string& text) {
        string decrypted = text;
        int length = text.length();
        for (int i = 0; i < length; i++) {
            decrypted[i] = text[i] - (i + 1);
        }
        return decrypted;
    }

public:
    TextEncryptor(string file) {
        fileName = file;
    }

    void EncryptAndSave() {
        cout << "Enter String: ";
        getline(cin, normalText);

        cout << "Normal Text: " << normalText << endl;

        encryptedText = EncryptText(normalText);

        ofstream outFile(fileName);
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted in file." << endl;
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
    }

    void ReadAndDecrypt() {
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            getline(inFile, encryptedText);
            inFile.close();

            decryptedText = DecryptText(encryptedText);

            cout << "Decrypted text Read then decoded from file:" << endl;
            cout << decryptedText << endl;
        } else {
            cout << "Unable to open file for reading!" << endl;
        }
    }
};

int main() {
    TextEncryptor encryptor("encrypted.txt");
    encryptor.EncryptAndSave();
    encryptor.ReadAndDecrypt();

    return 0;
}
