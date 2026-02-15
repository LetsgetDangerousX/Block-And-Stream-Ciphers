#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <functional>


std::vector<unsigned char> readFile(const std::string& filename);

void writeFile(const std::string& filename, const std::vector<unsigned char> & data);

bool fileExists(const std::string& filename);

bool validateArgs(int argc, char* argv[], std::string& cipherType, std::string& mode, std::string& inputFile, std::string& outputFile, std::string& keyFile);

#endif