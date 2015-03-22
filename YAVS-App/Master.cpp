
#include<string>

#include <fstream>

#include "Master.h"

#include "User.h"
#include "File.h"

CMaster::CMaster(string sFilename)
{
    AddUser(sFilename);
    
    // cout<< "AddUser"<<endl;
     
    CheckValidFile();
    
    //    cout<< "CheckValidFile"<<endl;
}

CMaster::~CMaster()
{
    //Clear list of user
    for( std::list<CUser*>::iterator ip = m_pUserList.begin(); ip!= m_pUserList.end(); ++ip)
        delete *ip;
    
    m_pUserList.clear();
    
    //Clear list of Files
        for( std::list<CFile*>::iterator ip = m_pCFileList.begin(); ip!= m_pCFileList.end(); ++ip)
        delete *ip;
    
    m_pCFileList.clear();
    
}


void CMaster::AddUser( std::string sFilename)
{
    cout<< sFilename<<endl;
    CUser* pCUser;

    string line;
    ifstream myfile(sFilename.c_str());

    if (myfile.is_open())
    {
        while ( getline (myfile, line) )
        {
            std::cout << line <<endl;
            
            pCUser = new CUser( line);
            AddList(pCUser);
        }
        myfile.close();
    }
}
 
void CMaster::AddList(CUser* pList)
{
    m_pUserList.push_back((pList));
}
void CMaster::AddVersion()
{
    CFile *pCFile = new CFile("");
    pCFile->UpdateVersion();
    Version( pCFile );
}
void CMaster::Version(CFile *pCFile)
{
    m_pCFileList.push_back(pCFile);
}

void CMaster::CheckIn()
{
    
}

void CMaster::CheckValidFile()
{
    bool bEnter = false;
    fstream Files("./master/.yavc/Entries");
    
    string value;
    while ( Files.good() )
    {
        bEnter = true;
        getline ( Files, value);  
        
        CFile* pCFile = new CFile(value);
         pCFile->ReadAllVersion(value); //read version config file
         Version(pCFile);
    }
    
    if( bEnter == false)
        AddVersion();
   
}

 bool CMaster::Login( std::string sUserId )
 {
     bool bRet = false;
     for(std::list<CUser*>::const_iterator it = m_pUserList.begin(); it != m_pUserList.end(); it++)
     {
         if( (*it)->GetUserName().compare(sUserId) == 0)
         {
             bRet = true;
             break;
         }
             
     }
     return bRet;
 }
 bool CMaster::FindFileName( std::string sFileName , CFile & pCFileName)
 {
     bool bRet = false;
     for(std::list<CFile*>::iterator it = m_pCFileList.begin(); it != m_pCFileList.end(); it++)
     {
         if( (*it)->GetFileName().compare(sFileName) == 0)
         {             
            bRet= true ; 
            break;
         }
             
     }
     return bRet;
 }