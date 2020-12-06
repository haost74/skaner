/*
  sudo apt-get install libsqlite3-dev
*/
#include <sqlite3.h> 
#include <iostream>
using std::cout;
#include <string>
using std::string;

void createDb(string nameDb);

int main()
{

  //createDb("openallPortInet.db");


    return 0;
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
}