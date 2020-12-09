#ifndef __sqlRequire__
#define __sqlRequire__

#include <sqlite3.h> 
#include <sqlite3.h> 
#include <string>
using std::string;

class sql
{
  private:
    std::string nameDb;
    const int STATEMENTS = 8;
	sqlite3 *db = nullptr;
	char *zErrMsg = 0;
	const char *pSQL[8];
    char* messageError = nullptr;
	int rc;
   public:
     sql(std::string name);
     ~sql(); 

    public:
      bool CreateTable(string sql);
      bool CreateDb();
      void CloseDb();
      bool Require(string strSql);
      static inline int callback(void* data, int argc, char** argv, char** azColName)
      {
           int i; 
            fprintf(stderr, "%s: ", (const char*)data); 
        
            for (i = 0; i < argc; i++) { 
                printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
            } 
        
            printf("\n"); 
            return 0; 
      }
};



#endif