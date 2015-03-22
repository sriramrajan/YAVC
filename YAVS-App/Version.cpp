
#include "Version.h"

CVersion::CVersion()
{
    mCVersionNo = 0;
    mCFilePath = "";
    mCLable = "";
    mCDateAndTime = "";
    mCUserID = "";
}

CVersion::~CVersion()
{
    cout<<"Distructor for the CVersion Class\n";
}

void CVersion::mfCUpdateVersion()
{
    mCVersionNo++;
    mCFilePath=MASTERDIR;
    mCLable="NewFile";
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    mCDateAndTime= buffer;
    cout<<"CVsersion::mfCUpdateVersion() Entered\n";
}

int CVersion::GetVersionNo()
{ 
    return  CVersion::mCVersionNo;
}

string CVersion::GetFilePath()
{
     return mCFilePath;
}

string CVersion::GetLabel()
{
    return mCLable;
}

string CVersion::GetDateAndTime()
{
    string mCDateAndTime;
}

string CVersion::GetUserName()
{
    string mCUserID;
}