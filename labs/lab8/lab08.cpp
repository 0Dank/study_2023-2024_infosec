#include <iostream>
#include <string>

std::string encrypt(std::string plaintext, std::string key)
{
    std::string ciphertext;
    for (int i = 0; i < plaintext.length(); ++i){ciphertext.push_back(plaintext[i] ^ key[i % key.length()]);}
    return ciphertext;
}

std::string decrypt(std::string ciphertext, std::string key){return encrypt(ciphertext, key);}

int main()
{

    std::string key = "@##?!#";
    std::string P1 = "Plain text 1";
    std::string P2 = "Plain text 2";

    std::string C1 = encrypt(P1, key);
    std::string C2 = encrypt(P2, key);

    std::cout << "Encrypted C1: " << C1 << std::endl;
    std::cout << "Encrypted C2: " << C2 << std::endl;

    std::string decryptedP1 = decrypt(C1, key);
    std::string decryptedP2 = decrypt(C2, key);

    std::cout << "Decrypted text 1: " << decryptedP1 << std::endl;
    std::cout << "Decrypted text 2: " << decryptedP2 << std::endl;

    return 0;
}