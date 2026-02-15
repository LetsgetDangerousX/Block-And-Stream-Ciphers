#### CS 356 PA1
#### Author: Amber Ferrell



# Block-And-Stream-Ciphers
This program is a command-line security tool that implements two different types of cryptography: a Stream Cipher and a Block Cipher. 

## Compile
```
bash
make

./cipher <B|S> <input> <output> <key> <E|D>
```

### Examples and Tests Ran
#### Block cipher

```
echo -n "abcdefghijklmnop" > key.txt
echo -n "lu" > input.txt
./cipher B input.txt out.txt key.txt E
hexdump -C out.txt
```

#### Stream Cipher
```
echo -n "Hello" > input.txt
echo -n "key" > key.txt
./cipher S input.txt out.txt key.txt E
./cipher S out.txt dec.txt key.txt D
cat dec.txt
```

### Error Messages
* Invalid Function Type - cipher not B or S
* Input File Does Not Exist - input missing
* Key File Does Not Exist - key missing
* Invalid Mode Type - mode not E or D

### Files
- main.cpp - program logic
- block.cpp/h - block cipher
- stream.cpp/h - stream cipher
- utility.cpp/h - file I/O & validation
- Makefile - build instructions

### Requirements
- C++ 11
- key file with no newline
- block key is 16 bytes


