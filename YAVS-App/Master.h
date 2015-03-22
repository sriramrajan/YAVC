#ifndef MASTER_H
#define	MASTER_H
#include<list>
#include <iostream>
#include<string>

class  CUser;
class CFile;

using namespace std;

class CMaster
{
private:
    std::list<CUser*> m_pUserList;
    std::list<CFile*> m_pCFileList;
    string sFilename;
public:
    
    CMaster(string sFilename);
    ~CMaster();
    void AddUser( std::string sFilename);
    void AddList(CUser* pList);
    void Version(CFile *pCFile);
    void AddVersion( );
    void CheckIn();   
    void CheckValidFile();
    bool Login( std::string sUserId );
    bool FindFileName( std::string sFileName , CFile & pCFileName);
};

#endif	/* MASTER_H */

