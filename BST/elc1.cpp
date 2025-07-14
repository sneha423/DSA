#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to read text from file
string readTextFromFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return text;
}

// Function to encrypt text using Caesar Cipher
string encryptCaesar(string text, int s) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + s - 65) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] + s - 97) % 26 + 97);
        } else {
            result += text[i]; // Non-alphabetic characters remain the same
        }
    }
    return result;
}

int main() {
    // User inputs the key
    int shift;
    cout << "Enter shift value for Caesar Cipher: ";
    cin >> shift;

    // Read text from file
    string text = readTextFromFile("sneha.txt");

    cout << "Encrypted Text: " << encryptCaesar(text, shift) << endl;
    return 0;
}




