#include "utility.h"

/*

Block Cipher
Pad 
Encrypt using XOR
Swap 

block: 16 bytes
read the whole input string, store in data structure like a vector adn then take 16 byte substring as blocks until you read the whole string 

OR

directly read in 16 byte blocks as chunks from the input file at atime until you reach the end of the file

if a block is found to be < 16 bytes should be padded to make 16
0x81 as paddingbyte

start and end be pointers that point to the start and end of xored output block
for each byte 0 -> n
ASCII value of byte % 2

*/

