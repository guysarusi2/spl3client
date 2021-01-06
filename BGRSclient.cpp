#include <stdlib.h>
#include "connectionHandler.h"
#include "MessageEncoderDecoder.h"
#include "Protocol.h"
#include <unordered_map>
#include <boost/thread/thread.hpp>


void readFromKeyboard(ConnectionHandler &connectionHandler, MessageEncoderDecoder &messageEncoderDecoder,
                      Protocol &protocol) {
    while (!protocol.getShouldTerminate()) {
        /**
         * input from keyboard
         * we would like to interrupt the thread
         */
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string input(buf);


        /**
         * splitting the given output by " " in to the vector
         */
        std::vector<std::string> messageToEncode;
        boost::split(messageToEncode, input, boost::is_any_of(" "), boost::token_compress_on);

        /**
         * we encode the given message in to vector-buffer
         * and finally move the content to the bufferToSend
         */
        std::vector<char> buffer;
        messageEncoderDecoder.createMessage(messageToEncode, buffer);
        int bufferToSendSize = buffer.size();
        char bufferToSend[bufferToSendSize];
        for (int i = 0; i < bufferToSendSize; i++) {
            bufferToSend[i] = buffer[i];
        }

        /**
         * we send the encoded bufferToSend using sendBytes()
         */
        if (!connectionHandler.sendBytes(bufferToSend, bufferToSendSize)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        //sleep on the future object until answer
        if (messageToEncode[0] == "LOGOUT") {
            if (!protocol.getLogoutFuture().get())
                protocol.setNewPromise(); //logout fail we need new promise
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    //connect to server
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    } else {
        std::cout << "connected" << std::endl;
    }

    //CREATE the meesage encoder-decoder, message protocol
    MessageEncoderDecoder messageEncoderDecoder;
    Protocol protocol;
    //CREATE the thread that read input keyboard and send the messages to server
    boost::thread keyboardThread(&readFromKeyboard, boost::ref(connectionHandler), boost::ref(messageEncoderDecoder),
                                 boost::ref(protocol));
    while (!protocol.getShouldTerminate()) {
        /**
         * we first get the command and message opcode and process them
         */
        char ch;
        std::vector<char> answerOpcodes;
        for (int i = 0; i < 4; i++) {
            if (!connectionHandler.getBytes(&ch, 1)) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
            answerOpcodes.push_back(ch);
        }

        std::vector<short> opcodesToProcess(messageEncoderDecoder.decodeOpcodes(answerOpcodes));
        bool extraInfo = protocol.process(opcodesToProcess);
        /**
         * if there is optional data we get it too and print it
         */
        if (extraInfo) {//optional data
            std::string optionalData;
            if (!connectionHandler.getFrameAscii(optionalData, '\0')) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
            std::cout << optionalData << std::endl;
        }
    }
    keyboardThread.join();
    return 0;
}
