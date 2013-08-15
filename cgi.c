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

        destory();
    }
    return 0;
}
