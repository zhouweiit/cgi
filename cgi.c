#include "cgi.h"

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
        printf("Content-type: text/html\r\n");
        cgiInit();
        
        run();

        destory();
    }
    return 0;
}
