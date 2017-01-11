#include "database.h"

database::database()
{
}

database::~database()
{
}

bool database::connect(){
    if (mysql_real_connect(conn,_host,_login,_password,_dbname,0,NULL,0) !=0)
        return true;
    else
        return false;
}

