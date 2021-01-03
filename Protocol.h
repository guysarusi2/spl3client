//
// Created by guy on 31/12/2020.
//

#ifndef ASSIGNMENT4_PROTOCOL_H
#define ASSIGNMENT4_PROTOCOL_H

#include <unordered_map>
#include <vector>
#include <string>

class Protocol {
public:
    Protocol();
    bool process(std::vector<short>&);

    bool getShouldTerminate();

private:
    bool shouldTerminate;
    std::unordered_map<short,std::string> serverMessages;
    bool checkExtraInfo(short);
};


#endif //ASSIGNMENT4_PROTOCOL_H
