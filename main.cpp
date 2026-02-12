#include "utility.h"
#include <iostream>
#include <string>
#include <fstream>



int main(int argc, char* argv[])
{
 char cipherType, mode;
 std::string inputFile, outputFile, keyFile;

// Steps main should orchestrate:

// validate arguments
// read key file
// block cipher key length validation
// read input file
// process abdedo n ciopher type
// write output file

if(!validateArgs(argc, argv, cipherType, mode, inputFile, outputFile, keyFile)
{return 1;}

        
return 0;
}