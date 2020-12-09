/*
  sudo apt-get install libsqlite3-dev
*/
#include <sqlite3.h> 
#include <iostream>
using std::cout;
#include <string>
using std::string;

#include "sqlRequire/sqlRequire.h"

void createDb(string nameDb);
void insertIp4All(sql &db);

int main()
{

  //createDb("openallPortInet.db");

 string namedb = "openallPortInet.db";
  sql db(namedb);
  db.CreateDb();

  std::string sql = "CREATE TABLE IPADDRES4("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "ADDRESS           TEXT    NOT NULL);"; 

    //db.CreateTable(sql);
   //auto res = db.Require("INSERT INTO IPADDRES4 VALUES(1, '000.000.000.000')");
   //auto res  = db.Require("SELECT * FROM IPADDRES4");
   //std::cout << res << '\n';

    insertIp4All(db);

   //db.Require("delete from IPADDRES4");

    auto res  = db.Require("SELECT count(*) FROM IPADDRES4");


  db.CloseDb();
    return 0;
}

long long i = 0;

int Insert(sql &db, string& str)
{
    ++i;
    auto res = db.Require("INSERT INTO IPADDRES4 VALUES(" + std::to_string(i) + ", '" + str + "')");
    return res;
}

void insertIp4All(sql& db)
{
  int firstNum = 0;
  int secondNum = 0;
  int thirdNum = 0;
  int fourthNum = 0;
  string oldIp{""};

  while (firstNum <= 9999)
  {
    
    if(oldIp != "")
    {
       
       if(fourthNum < 9999)
       {
           ++fourthNum;
           oldIp = std::to_string(firstNum) + "." + std::to_string(secondNum) + "." + std::to_string(thirdNum) + "." + std::to_string(fourthNum);
           Insert(db, oldIp);    
       }
       else if(thirdNum < 9999)
       {
           fourthNum = 0;
           ++thirdNum;
           oldIp = std::to_string(firstNum) + "." + std::to_string(secondNum) + "." + std::to_string(thirdNum) + "." + std::to_string(fourthNum);
           Insert(db, oldIp); 
       }
       else if(secondNum < 9999)
       {
           std::cout << secondNum << '\n';
           fourthNum = 0;
           thirdNum = 0;
           ++secondNum;
           oldIp = std::to_string(firstNum) + "." + std::to_string(secondNum) + "." + std::to_string(thirdNum) + "." + std::to_string(fourthNum);
           Insert(db, oldIp);

       }
       else if(firstNum < 9999)
       {
           fourthNum = 0;
           thirdNum = 0;
           secondNum = 0;
           ++firstNum;
           oldIp = std::to_string(firstNum) + "." + std::to_string(secondNum) + "." + std::to_string(thirdNum) + "." + std::to_string(fourthNum);
           Insert(db, oldIp);
       }
    }
    else
    {
        oldIp = std::to_string(firstNum) + "." + std::to_string(secondNum) + "." + std::to_string(thirdNum) + "." + std::to_string(fourthNum);
        Insert(db, oldIp);
    }
  }
  

}





void createDb(string nameDb)
{
    const int STATEMENTS = 8;
	sqlite3 *db;
	char *zErrMsg = 0;
	const char *pSQL[STATEMENTS];
	int rc;
     // this.deleteDatabase("databasename.db");
     
	rc = sqlite3_open(nameDb.c_str(), &db);

    if( rc )
	{
		cout<<"Can't open database: "<<sqlite3_errmsg(db)<<"\n";
	} 
	else
	{
		cout<<"Open database successfully\n\n";
	}

    sqlite3_close(db);
}