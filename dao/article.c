#include "article.h"

int selectAllArticle(dlist **list){
    char *sql = "select * from article "; 
    sqlite3 *db = (sqlite3 *)createConnectionSqlite3("db/message.db");
    selectSqlite3(db,sql,list); 
    closeSqlite3(db);
}


int insertArticle(char *name,char *message,char *datetime){
    char *sql = (char *)malloc(140 + strlen(name) + strlen(message));
    sqlite3 *db = (sqlite3 *)createConnectionSqlite3("db/message.db");
    sprintf(sql,"insert into article (title,content,author,creation_date,last_changed_date) values ("
        "'test','%s','%s','%s','%s')\0",message,name,datetime,datetime);
    insertSqlite3(db,sql);
    closeSqlite3(db); 
    _free(sql);
}
