
#include <string>
#include<iostream>
#include <fstream>

#include "client.h"
#include "File.h"
#include"CheckInWrite.h"



void CCheckInWrite::cmUpdate(string filename,CFile &pCFile, std::string sUserName)
{    
    //cout<<"Eneter"<<endl;
    
      std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    //TODO: Validate userID before continuing
    
    //TODO: Find if the version needs updating, if so pass on CheckIn to another fn
    _copyFile(filename,"./master/"+filename);
 
    //string ConfigName = "./master/.yavc/"+filename+"_config";
    //ofstream OutConfig(ConfigName.c_str());
    
    string Entries = "./master/.yavc/Entries";
    fstream EntriesUpdate(Entries.c_str(), std::fstream::app);
    
    EntriesUpdate <<filename<<endl;
    EntriesUpdate.close();
    
    //OutConfig <<"1,"<<filename<<","<<sUserName<<","<<buffer<<endl;
    //OutConfig.close(); 
    
    pCFile.WriteVersion((CVersion*)this );
}

void CCheckInWrite::_copyFile(string source, string destination)
{
    cout <<"Enter"<<source<<","<<destination<<endl;
    fstream file (source.c_str());
    //TODO: Find if the version needs updating, if so pass on CheckIn to another fn
    ofstream OutFile(destination.c_str());
    string LineFile = "";
    
    cout<<"here"<<file.good()<<endl;
    while (file.good() )
    {
      
        getline( file, LineFile);
        
          cout<<"CopyFile: "<<LineFile <<endl;
        OutFile<<LineFile<<endl;
    }
    OutFile.close();

}