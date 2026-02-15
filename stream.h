#ifndef STREAM_H
#define STREAM_H

#include <vector>
#include <string>

class StreamCipher {
    public:
    static std::vector<unsigned char> process(const std::vector<unsigned char>& input, const std::string& key);
};

#endif