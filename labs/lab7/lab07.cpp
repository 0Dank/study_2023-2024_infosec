#include <iostream>
#include <string>
#include <windows.h>

std::string encryptdecrypt(std::string text, std::string key)
{
    std::string result;
    int keyLength = key.length();

    for (std::size_t i = 0; i < text.length(); ++i)
    {
        result += text[i] ^ key[i % keyLength];
    }

    return result;
}

std::string findpossiblekeys(std::string text, std::string fragment) 
{
    std::string possible_keys;

    for (int i = 0; i <= (int)text.length() - fragment.length(); i++)
    {
        std::string key = "";
        for (int j = 0; j < fragment.length(); j++) 
        {
            char c = text[i + j] ^ fragment[j];
            key.push_back(c);
        }

        std::string intact_plaintext = encryptdecrypt(text, key);

        if (intact_plaintext.find(fragment) != std::string::npos){possible_keys += key;}
    }

    return possible_keys;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string plaintext = "";
    std::string key = "%#2!";
    std::string fragtext;

    std::cout << "Plain text: ";
    std::getline(std::cin, plaintext);

    std::string ciphertext = encryptdecrypt(plaintext, key);
    std::cout << "Encrypted text: " << ciphertext << std::endl;

    std::string decryptedText = encryptdecrypt(ciphertext, key);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    std::cout << "Plain text fragment: ";
    std::getline(std::cin, fragtext);

    std::string possibleKey = findpossiblekeys(ciphertext, fragtext);

    std::cout << possibleKey;

    return 0;

}
