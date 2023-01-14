#include <iostream>
#include <string>
#include <sstream>

std::string encryptDecrypt(std::string toEncrypt) {
    char key = 'K'; // Any char will work
    std::string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;

    return output;
}

std::string hexToString(std::string hex) {
    std::stringstream ss;
    for (int i = 0; i < hex.length(); i += 2)
        ss << (char)std::stoi(hex.substr(i, 2), nullptr, 16);
    return ss.str();
}

std::string stringToHex(std::string input) {
    std::stringstream ss;
    for (int i = 0; i < input.length(); i++)
        ss << std::hex << (int)input[i];
    return ss.str();
}

int main() {
    while(1){
        std::cout << "1. Enkripsi" << std::endl;
        std::cout << "2. Deskripsi" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        int pilih;
        std::cin >> pilih;

        if (pilih == 1){
            std::string input;
            std::cout << "Masukkan pesan yang ingin dienkripsi: ";
            std::cin.ignore();
            std::getline(std::cin, input);
            std::string encrypted = encryptDecrypt(input);
            std::cout << "Hasil enkripsi: " << stringToHex(encrypted) << std::endl << std::endl;
        }
        else if (pilih == 2){
            std::string input;
            std::cout << "Masukkan pesan yang ingin didekripsi: ";
            std::cin.ignore();
            std::getline(std::cin, input);
            std::string decrypted = encryptDecrypt(hexToString(input));
            std::cout << "Hasil deskripsi: " << decrypted << std::endl << std::endl;
        }
        else if (pilih == 3)
            break;
    }
    return 0;
}
