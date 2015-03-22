
#include <fstream>
#include <ctime>

#include "client.h"
#include "Master.h"
#include "File.h"
#include "CheckInWrite.h"

void Client::_copyFile(string source, string destination)
{
    fstream file (source.c_str());
    //TODO: Find if the version needs updating, if so pass on CheckIn to another fn
    ofstream OutFile(destination.c_str());
    string LineFile = "";
    
    while (file.good() )
    {
        getline( file, LineFile);
        OutFile<<LineFile<<endl;
    }
    
    OutFile.close();
}

void Client::CheckIn(string filename, string userId ) {
    
    
    /*std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    //TODO: Validate userID before continuing
    
    //TODO: Find if the version needs updating, if so pass on CheckIn to another fn
    _copyFile(filename,"./master/"+filename);
 
    string ConfigName = "./master/.yavc/"+filename+"_config";
    ofstream OutConfig(ConfigName.c_str());
    
    string Entries = "./master/.yavc/Entries";
    fstream EntriesUpdate(Entries.c_str(), std::fstream::app);
    
    EntriesUpdate <<filename<<endl;
    EntriesUpdate.close();
    
    OutConfig <<"1,"<<filename<<","<<userId<<","<<buffer<<endl;
    OutConfig.close();
    
    */

}

void Client::CheckOut() {
    //TODO: Get List of files from "Entries"
    fstream Files("./master/.yavc/Entries");
    
    string value;
    while ( Files.good() )
    {
        getline ( Files, value);
        this->_copyFile("./master/"+value, "./slave/"+value);
        //Create backup for Undo - Memento pattern
        _copyFile("./master/"+value, "./slave/.undo_"+value);        
    }   
    
}

void Client::Undo() {
    //TODO: Get last known checkout file
    
    fstream Files("./master/.yavc/Entries");
    
    string value;
    while ( Files.good() )
    {
        getline ( Files, value);

        //Restore backup for Undo - Memento pattern
        _copyFile("./slave/.undo_"+value, "./slave/"+value);
        
    }
}

int main(int argc, char **argv) {
   
   
    const char* cUserName;
    const char* cCommand;
    const char* cFileName;
   //Client * test = new Client();
   if (argc < 2) {
        return -1;
    }
    if( argc >=1 )
         cUserName = argv[1];

     if( argc >= 2)
        cCommand = argv[2];

     if( argc >= 3 )
       cFileName = argv[3];

   string sUser = (string)cUserName;
   string sCommand = (string) cCommand;

   //string sCommand 
    
   Client* pClient;
   CMaster * localMaster = new CMaster("./users.txt");
   
   if( localMaster->Login( sUser ) == false )  
       return 0;
   else
   {
       if( sCommand.compare("check_out") == 0 )
       {
          pClient = new Client();
          pClient->CheckOut();
            //Call Checkout funct
       }
       else if(sCommand.compare("check_in") == 0)
        {
           CFile objCFile;
               if( cFileName != "")
               {
                   if((localMaster->FindFileName(cFileName,objCFile) == 1) || ((localMaster->FindFileName("",objCFile) == 1)))                 
                   {
                       objCFile.SetFileName(cFileName);
                       CCheckInWrite *pCCheckInWrite = new CCheckInWrite();
                       pCCheckInWrite->cmUpdate(cFileName, objCFile, cUserName);
                    }
                    
               }
             
            
        }
        else if(sCommand.compare("undo" ) == 0 )
        {
               pClient->Undo();//Undo 
              
        }
        else if(sCommand.compare("versiontree")  == 0)
        {
           if( cFileName != "" )
           {
               CFile objCFile;
               if((localMaster->FindFileName(cFileName,objCFile) == 1) || ((localMaster->FindFileName("",objCFile) == 1)))
               { 
                   std::list<CVersion*> pList = objCFile.GetVersionList();
                
                   cout<<"Version No"<< "Date and Time" << "User" << "Label"<<endl;
                for( std::list<CVersion*>::iterator it = pList.begin(); it!= pList.end(); ++it)
                {
                    cout<< (*it)->GetVersionNo() << (*it)->GetDateAndTime() << (*it)->GetUserName() << (*it)->GetLabel()<<endl;
                    
                }
               }
               
           }
               
        }
               
      
    }
   
   //Debug to add a file
   //test->CheckIn("users.txt", "someuser");

    //Debug checkout
    //test->CheckOut("testuser");
    
    //Debug Undo
    
    //test->Undo();
   
    
   return 0;
}
