#include "utility.h"
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <vector>

// readFile into vector of bytes

// get file size
// read entire file
// write vector of bytes to file
// check if file exists
// validate command lines args
// check cipher type
// check input file
// output file will be created
// check key file
// check mode

// moving from main:


bool existingFile(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
bool validateArgs(int argc, char* argv[], std::string& cipherType, std::string& mode, std::string& inputFile, std::string& outputFile, std::string& keyFile)
{
    if (argc != 6) {
            exit(1);}

    cipherType = argv[1];
    inputFile= argv[2];
    outputFile=argv[3];
    keyFile = argv[4];
    mode = argv[5];

    

    if (cipherType != "B" && cipherType != "S"){
        std::cerr << "Invalid Function Type" << std::endl;
        exit(1);
    }       
   
    
    if (!existingFile(inputFile)){
        std::cerr << "Input File Does Not Exist" << std::endl;
        exit(1);
    }

    if(!existingFile(keyFile)) {
        std::cerr << "Key File Does Not Exist" << std::endl;
        exit(1);
    }

    if (mode!= "E" && mode!= "D"){
        std::cerr << "Invalid Mode Type" << std::endl;
        exit(1);
    }
    return true;
}

std::vector<unsigned char> readFile(const std::string& filename){
    std::ifstream file(filename.c_str(), std::ios::binary);
    if(!file){
        std::exit(1);
    }

    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> buffer(size);
    if(size>0){
        file.read(reinterpret_cast<char*>(buffer.data()), size);
    }
    file.close();
    return buffer;
}
void writeFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename.c_str(), std::ios::binary);
    if(!file){
        std::exit(1);
    }
    if(!data.empty()){
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
    }
    file.close();
}