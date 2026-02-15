#include "utility.h"
#include <iostream>
#include <string>
#include <vector>
#include "block.h"
#include "stream.h"


int main(int argc, char* argv[])
{
 std::string cipherType, mode, inputFile, outputFile, keyFile;


//validata
if(!validateArgs(argc, argv, cipherType, mode, inputFile, outputFile, keyFile)){
    return 1;
}

// read key file, convert to string
std::vector<unsigned char> keydata = readFile(keyFile);
std::string key(keydata.begin(), keydata.end());

// block cipher key length validate
if(cipherType == "B" && key.length() !=16){return 1;}

// read input fil
std::vector<unsigned char> inputData = readFile(inputFile);
std::vector<unsigned char> outputData;

//  ciopher type
if(cipherType == "B"){
    if(mode == "E"){
        outputData = BlockCipher::encrypt(inputData, key);
    }else{
        outputData = BlockCipher::decrypt(inputData, key);
    }
}else {
    outputData = StreamCipher::process(inputData, key);
}
// write output file
writeFile(outputFile, outputData);

        
return 0;
}