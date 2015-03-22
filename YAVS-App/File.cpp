
#include <iostream>
#include <fstream>
#include <sstream>
#include "File.h"
#include "Version.h"

CFile::CFile()
{
}

CFile::CFile(string mFileName) : m_FileName(mFileName)
{
    
}

CFile::~CFile()
{
    
}

void CFile::UpdateVersion()
{
  CVersion *mVersion = new CVersion();
  mVersion->mfCUpdateVersion();
   m_pVersionList.push_back(mVersion);  
}

CVersion* CFile::GetVersion()
{
    //need to check
    CVersion* pCVersion;
    
    if( m_pVersionList.size() > 0 )
       pCVersion =  m_pVersionList.back();
    return pCVersion;
}

void CFile::AddVersionList(CVersion *pCVersion)
{
    if( pCVersion)
        m_pVersionList.push_back(pCVersion);
}

void CFile::GenerateVersionTree()
{
    std::list<CVersion*> pVersionList;
    
     if( m_pVersionList.size() > 0 )
     {
         for (std::list<CVersion*>::const_iterator it = m_pVersionList.begin(); it != m_pVersionList.end() ; ++it)
         {
             pVersionList.push_back(((*it)));
         }
     }
}

void CFile::WriteVersion(CVersion* pCVersion )
{
    unsigned found = m_FileName.find_last_of(".");
     string sFileName =  m_FileName.substr(0, found);  
     
    string sFln = "./master/.yavc/"+sFileName+ "_config";
    std::ofstream ofs(sFln.c_str(), std::ios::binary);
    ofs.write((char *)&pCVersion, sizeof(pCVersion));
}

void CFile::ReadAllVersion(std::string sName)
{
     CVersion* pCVersion;
     
     unsigned found = sName.find_last_of(".");
     string sFileName =  sName.substr(0, found);     
    // std::ofstream ofs("fifthgrade.ros", std::ios::binary);
     std::string sn = sFileName + "_config";
     
     std::stringstream ss;
     ss << "./master/.yavc/" << sFileName << "_config";
     
     std::string sFilename1 = ss.str();
//     sstream ss = "./master/.yavc/";// + sFileName.c_str() + "_config";
     std::ifstream ifs(sFilename1.c_str() , std::ios::binary);
     while(!ifs.eof())
     {
        pCVersion = new CVersion();
        //ofs.write((char *)&pCVersion, sizeof(pCVersion));
        ifs.read((char *)&pCVersion, sizeof(pCVersion));
        AddVersionList(pCVersion);
     }
    
}
void CFile::AddVersion()
{
    CVersion *mVersion = new CVersion();
    m_pVersionList.push_back(mVersion);
}

void CFile::SetFileName(string mFilename){
    m_FileName = mFilename;
}

std::string CFile::GetFileName()
{
    return m_FileName;
}

std::list<CVersion*> CFile::GetVersionList()
{
    return m_pVersionList;
}