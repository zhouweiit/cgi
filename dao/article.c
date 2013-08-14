#include "article.h"

int selectAllArticle(dlist **list){
    char *sql = "select * from article "; 
    sqlite3 *db = (sqlite3 *)createConnectionSqlite3("db/message.db");
    selectSqlite3(db,sql,list); 
    closeSqlite3(db);
}
