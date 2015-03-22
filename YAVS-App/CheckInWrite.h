#ifndef CHECKINWRITE_H
#define	CHECKINWRITE_H

#include<iostream>
#include"Version.h"


using namespace std;
class CFile;
class CCheckInWrite :public CVersion{
    public:
        void _copyFile(string source, string destination);
        void cmUpdate(string filename,CFile &pCFile, std::string sUsername);

};


#endif	/* CHECKINWRITE_H */

