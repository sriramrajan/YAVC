


#ifndef FILE_H
#define	FILE_H
#include<list>
#include <string>
using namespace std;
class CVersion;

class CFile
{
private:
    std::list<CVersion*> m_pVersionList;
    string m_FileName;
    
public:
    CFile();
    CFile(string mFilename);
    ~CFile();
    void AddVersion();
    void UpdateVersion();
    CVersion* GetVersion();
    void AddVersionList(CVersion *pCVersion);
    void GenerateVersionTree();
    void WriteVersion(CVersion* pCVersion);
    void ReadAllVersion(std::string sName);
    void SetFileName(string mFilename);
    std::string GetFileName();
    std::list<CVersion*> GetVersionList();
   
};


#endif	/* FILE_H */

