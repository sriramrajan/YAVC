
#ifndef VERSION_H
#define	VERSION_H

#include <iostream>
#include <ctime>
#define MASTERDIR "./master"
using namespace std;
class CVersion
{
    int mCVersionNo;
    string mCFilePath;
    string mCLable;	
    string mCDateAndTime;
    string mCUserID;
    
    public:
        
    CVersion();
    ~CVersion();
    string GetUserName();
    string GetDateAndTime();
    string GetLabel();
    string GetFilePath();
    int GetVersionNo();
    
    
    virtual void mfCUpdateVersion();
};

#endif	/* VERSION_H */

