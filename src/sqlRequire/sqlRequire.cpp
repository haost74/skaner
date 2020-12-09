#include "sqlRequire.h"
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>

#include <iostream>

sql::sql(string name)
{
  nameDb = name;
}

sql::~sql()
{
     std::cout << "end" << '\n';
}

bool sql::CreateDb()
{
  	rc = sqlite3_open(nameDb.c_str(), &db);       
    return rc;
}

bool sql::CreateTable(string strSql)
{
    if(strSql.length() ==0) return 0;
    int res{0};
    if(rc == SQLITE_OK)
    {
      return sqlite3_exec(db, strSql.c_str(), NULL, 0, &messageError); 
    }

    return 0;
}

bool sql::Require(std::string strSql)
{
  if(rc != SQLITE_OK) return 0;
  try
  {      
    return sqlite3_exec(db, strSql.c_str(), callback, 0, &messageError); 
  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }

  return 0;
  
}

void sql::CloseDb()
{
    try
    {
         if(db != nullptr)
         {
           sqlite3_close(db);
         }  

         if(messageError != nullptr)
         {
             delete[] messageError;
         }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


