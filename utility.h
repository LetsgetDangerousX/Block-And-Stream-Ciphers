#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <functional>


void processFileChunks(const std::string& filename, std::function<void(const std::vector<unsigned char>&, bool)> processChunks, size_t chunkSize=16);

void writeFile(const std::string& filename, const std::vector<unsigned char> & data);

bool fileExists(const std::string& filename);

bool validateArgs(int argc, char* argv[], char& cipherType, char& mode, std::string& inputFile, std::string& outputFile, std::string& keyFile);

#endif