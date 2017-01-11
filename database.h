#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>

#include </usr/include/mysql/mysql.h>
#include </usr/include/mysql/my_global.h>

using namespace std;

class database
{
public:
    database();
    ~database();
    
    bool connect();
    
    MYSQL* conn = mysql_init(NULL);
    char *_host = "mysql1.paris1.alwaysdata.com";
    char *_login ="talai";
    char *_password = "talai2016";
    char *_dbname = "talai_qp";
    
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    
    

};

#endif // DATABASE_H
