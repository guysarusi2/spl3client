//#include <iostream>
//#include "connectionHandler.h"
//#include "MessageEncoderDecoder.h"
//#include <boost/thread/thread.hpp>
//
//
//using namespace std;
//
////template<typename T>
//
////bool from_string(short &t,const string &s,ios_base & (*f)(ios_base&)=std::dec){
////    istringstream iss(s);
////    return !(iss>>f>>t).fail();
////}
//void print() {
//    const short bufsize = 1024;
//    char buf[bufsize];
//    std::cin.getline(buf, bufsize);
//    std::string input(buf);
//    cout << "input: " << input << endl;
//}
//
//int main() {
//    //std::cout << "Hello, World!" << std::endl;
//    short bytesToShort(const char *);
//    void shortToBytes(short, char *);
//
//    short bufsize = 1024;
//    char buf[bufsize];
//    int len(0);
//
////    string s("1237");
////    short a;
////    from_string(a,s);
////    cout<<a;
//
////    vector<int> a;
////    a.push_back(1);
////    // boost::thread t1(&print);
////    std::thread t1(&print);
////    try {
////        std::this_thread::sleep_for(std::chrono::seconds(3));
////    } catch (std::exception &e) {}
////    string s("guysa\n""morthy\n""a123");
////    cout << s << endl;
////    t1.detach();
//    //t1.join();
//
////    cin.getline(buf, bufsize);
////    string s(buf);
//
////    cin.getline(buf, bufsize);
////    string s(buf);
//
////    string s("guysa");
////    for (int i=0;i<s.size();i++)
////        cout << s[i]<<" ";
////cout<<endl;
////    for (int i=0;i<s.length();i++)
////        cout << s[i]<<" ";
//
////    vector<std::string> message;
////    boost::split(message, s, boost::is_any_of(" "), boost::token_compress_on);
////    MessageEncoderDecoder m;
////    vector<char> buff;
////    m.createMessage(message, buff);
////
////    int bufferToSendSize = buff.size();
////    char bufferToSend[bufferToSendSize];
////    for (int i = 0; i < bufferToSendSize; i++) {
////        bufferToSend[i] = buff[i];
////    }
////    for (int i = 0; i < buff.size(); i++) {
////        cout << bufferToSend[i] << endl;
////    }
////    cout<<bufferToSendSize;
////
//
//
//
//    //    for(int i=0;i<message.size();i++) {
////        cout << message[i]<< endl;
////    }
////    for (int i = 0; i < message.size(); ++i) {
////        for (int j = 0; j < message[i].size(); ++j) {
////            buf[len] = message[i][j];
////            len++;
////        }
////        buf[len]='\0';
////        len++;
////    }
////
////    cout<<"buf size: "<<len<<endl;
////    for(int i=0;i<len;i++){
////        cout<< buf[i];
////    }
//
//    //const char* bytes(message[0].c_str());
////    const char *bytes(s.c_str());
////    cout << "bytes array: " << bytes << endl;
////    for (int i = 0; i < s.length(); i++) {
////        cout << "bytes[" << i << "]: " << bytes[i] << endl;
////    }
////
//
///**
// * print hex of the short
// */
////    short a(bytesToShort(bytes));
////    cout << "short zubra: " << hex <<a << endl;
//
//
////    for (int i = 0; i < s.length(); i += 2) {
////        // cout <<"short: "<< (short) ((bytes[i] & 0xff) << 8)<<endl;
////        // cout << "hex: "<< hex << (short) ((bytes[i] & 0xff) << 8)<<endl;
////        if (i == s.length() - 1)
////            cout << "hex: " << hex << (short) ((bytes[i] & 0xff) << 8) << endl;
////        else
////            cout << "hex: " << hex << (short) (((bytes[i] & 0xff) << 8) + (bytes[i + 1] & 0xff)) << endl;
////    }
//
///**
// * important
// */
////    char bytes1[2];
////    short b(0x0002);
////    shortToBytes(b,bytes1);
////    printf("%02x",bytes1[0]);
////    printf("%02x",bytes1[1]);
////
////    short b(2);
////    char bytes[2];
////    shortToBytes(b,bytes);
////    printf("%02x",bytes[0]);
////    printf("%02x",bytes[1]);
////    printf("\n");
//
//    //    short a(bytesToShort(bytes));
////    cout<<"a:"<< a<<endl;
//
//
//    // cout << hex<< bytes1[0] <<"  "<<hex<< bytes1[1];
//
////    {000000,00000010}
//
//    return 0;
//}
//
//short bytesToShort(const char *bytesArr) {
//    short result = (short) ((bytesArr[0] & 0xff) << 8);
//    result += (short) (bytesArr[1] & 0xff);
//    return result;
//}
//
//void shortToBytes(short num, char *bytesArr) {
//    bytesArr[0] = ((num >> 8) & 0xFF);
//    bytesArr[1] = (num & 0xFF);
//}
//
//
//class KeyboardReader {
//
//};
