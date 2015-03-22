#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include<string>
#include <fstream>
#include <ctime>
using namespace std;

using namespace std;
class Client {
    bool m_bValid;
    
    void _copyFile(string source, string destination); 
    public:
    Client() { m_bValid = false; }
    void CheckIn(string filename, string userId);
    void CheckOut();
    void Undo();
    
};
#endif