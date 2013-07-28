#include "cgi.h"
#include "util/db.h"
#include "util/dlist.h"

static void cgiInit(){
    httpInit();
}

static void destory(){
    httpDestroy(); 
}

static void run(){
    route(SERVER->scriptName);
    sendHtml();
}


int main (){
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html;charset=utf-8\r\n");
        cgiInit();
        
        run();

        sqlite3 *db = (sqlite3 *)createConnectionSqlite3("db/message.db");
        char *sql = "insert into article (title,content,author,creation_date,last_changed_date) values ("
            "'测试','测试内容',':-)','2013-07-28 18:00:00','2013-07-28 18:00:00')";
        
        char *sql1= "update article set title = '1234' where id = '1' or id = '2'";
        int a;
        updateSqlite3(db,sql1,&a);
        printf("%d",a);
        closeSqlite3(db);
        
        destory();
    }
    return 0;
}
