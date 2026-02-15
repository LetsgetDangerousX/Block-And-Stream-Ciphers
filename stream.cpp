#include "stream.h"

std::vector<unsigned char> StreamCipher::process(const std::vector<unsigned char>& input, const std::string& key){

    // handle the empties :)
    if(input.empty()) {
        return std::vector<unsigned char>();
    }

    std::vector<unsigned char> result(input.size());

    // free to xor with the key as long as needed
    for(std::size_t i = 0;
        i < input.size(); ++i)
        {result[i] = input[i] ^ key[i % key.length()];}
        return result;
}