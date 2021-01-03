//
// Created by guy on 29/12/2020.
//

#include "encoderdecoder.h"

encoderdecoder::encoderdecoder(): len(0), opCode({{"ADMINREG",     1},
                                                  {"STUDENTREG",   2},
                                                  {"LOGIN",        3},
                                                  {"LOGOUT",       4},
                                                  {"COURSEREG",    5},
                                                  {"KDAMCHECK",    6},
                                                  {"COURSESTAT",   7},
                                                  {"STUDENTSTAT",  8},
                                                  {"ISREGISTERED", 9},
                                                  {"UNREGISTER",   10},
                                                  {"MYCOURSES",    11},
                                                  {"ACK",          12},
                                                  {"ERR",          13}}) {};

std::string encoderdecoder::decodeNextByte(char nextByte) {
    return std::string();
}

void encoderdecoder::encode(vector<string> message, char& buf) {
    //going over the vector strings
    //for each string translate it to char bytes and add to the buf
    //
    for (int i = 0; i < message.size(); ++i) {
        for (int j = 0; j < message[i].size(); ++j) {
            bytes[len] = message[i][j];
            len++;
        }
    }
}

