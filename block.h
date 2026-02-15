#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

class BlockCipher{

    public:

    static const int BLOCK_SIZE = 16;
    static const unsigned char PAD_BYTE;

    // call upon by main
    static std::vector<unsigned char> encrypt(const std::vector<unsigned char>&input, const std::string& key);

    static std::vector<unsigned char> decrypt(const std::vector<unsigned char>& input, const std::string& key);
    
    // helpers

    private:
    static std::vector<unsigned char> pad(const std::vector<unsigned char>& block);

    static std::vector<unsigned char> unpad(const std::vector<unsigned char>& block);

    static std::vector<unsigned char> xor_with_key(const std::vector<unsigned char>& block, const std::string& key);

    static std::vector<unsigned char> swap(const std::vector<unsigned char>& block, const std::string& key);
};

#endif