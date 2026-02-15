#include "block.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>



// pad function
const unsigned char BlockCipher::PAD_BYTE = 0x81;

std::vector<unsigned char> BlockCipher::pad(const std::vector<unsigned char>& block){
    std::vector<unsigned char> padded = block;
    while (padded.size() < BLOCK_SIZE){
        padded.push_back(PAD_BYTE);
    }
    return padded;
}

// unpad function
std::vector<unsigned char> BlockCipher::unpad(const std::vector<unsigned char>& block){
    std::vector<unsigned char> unpadded = block;
    while (!unpadded.empty() && unpadded.back() == PAD_BYTE){
        unpadded.pop_back();
    }
    return unpadded;
}

//XOR function
std::vector<unsigned char> BlockCipher::xor_with_key(const std::vector<unsigned char>& block, const std::string& key){
    std::vector<unsigned char> result(block.size());
    for (
        std::size_t i = 0;
         i < block.size(); 
         ++i)
         {result[i] = block[i] ^ key[i % key.length()];
}
return result;
}


//SWAP function
std::vector<unsigned char> BlockCipher::swap(const std::vector<unsigned char>& block, const std::string& key) {
    int start = 0;
    int end = BLOCK_SIZE -1;
    std::size_t keyi = 0;
    std::vector<unsigned char> swapped = block;

    while(start < end) {
        if (key[keyi] % 2 ==1) {
            unsigned char temp = swapped[start];
            swapped[start] = swapped[end];
            swapped[end] = temp;
            start++;
            end--;
        }else{
            start++;
        
    }


    keyi = (keyi + 1) % key.length();
}
    return swapped;
}  




//Encrypt -> Pad -> XOR -> Swap

std::vector<unsigned char> BlockCipher::encrypt(const std::vector<unsigned char>& input, const std::string& key){
    std::vector<unsigned char> result;

    //1 process input in 16 byte blocks

    for(std::size_t i =0; i < input.size(); i += BLOCK_SIZE) 
    {
        std::size_t remains = input.size() - i;
        std::size_t toCopy = std::min<std::size_t>(remains, BLOCK_SIZE);
        std::vector<unsigned char> block(input.begin() + i, input.begin() + i + toCopy);
    
        if (block.size() < BLOCK_SIZE){block = pad(block);}

        std::vector<unsigned char>xored= xor_with_key(block, key);
        std::vector<unsigned char> swapped = swap(xored, key);
        result.insert(result.end(), swapped.begin(), swapped.end());
    }
    
    return result;
}

//Decrypt - > Swap -> XOR -> unpad

std::vector<unsigned char> BlockCipher::decrypt(const std::vector<unsigned char>& input, const std::string& key) {

    std::vector<unsigned char> result;

    // input : multiple of BLOCK_SIZE 
    for (std::size_t i = 0; i < input.size(); i += BLOCK_SIZE)
    {
        std::vector<unsigned char> block(input.begin() + i, input.begin()+ i + BLOCK_SIZE);

        std::vector<unsigned char> swapped = swap(block, key);
        std::vector<unsigned char> xored = xor_with_key(swapped, key);
        result.insert(result.end(), xored.begin(), xored.end());
    }
    
    return unpad(result);

}