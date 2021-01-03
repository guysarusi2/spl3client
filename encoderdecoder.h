//
// Created by guy on 29/12/2020.
//

#ifndef ASSIGNMENT4_ENCODERDECODER_H
#define ASSIGNMENT4_ENCODERDECODER_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class encoderdecoder {
private:
    //const int size;
    char bytes[1024];
    int len;
    unordered_map<string, short> opCode;


public:
    encoderdecoder();

    std::string decodeNextByte(char nextByte);

    void encode(std::vector<string> message, char& buf);

};


#endif //ASSIGNMENT4_ENCODERDECODER_H
