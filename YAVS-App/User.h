
#include<iostream>

#ifndef USER_H
#define	USER_H

class CUser
{
private:
    static int m_stUserId;
    int m_iID;
    std::string m_sUserName;
    
public:
    CUser(std::string sUserName);
    ~CUser();
    int GetUserId();
    std::string GetUserName();    
};


#endif	/* USER_H */

