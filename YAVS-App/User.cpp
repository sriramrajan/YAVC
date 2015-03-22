#include "User.h"

int CUser::m_stUserId = 0;

CUser::CUser( std::string sUserName)
{
   m_iID = ++m_stUserId;
    m_sUserName = sUserName; 
}

CUser::~CUser()
{
    
}
int CUser::GetUserId()
{
    return m_iID;
}
std::string CUser::GetUserName()
{
    return m_sUserName;
}

