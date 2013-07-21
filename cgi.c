#include "cgi.h"


static void cgiInit(){
    httpInit();
}

static void destory(){
    httpDestroy(); 
}

static void run(){
    printf( "Status: 200 OK\r\n"
            "Test-head-1:test\r\n"
            "Content-type: text/html\r\n"
            "Test-head-2:test\r\n"
            "\r\n"
            "");
    printf("%s",html);
}

int main (){
    while (FCGI_Accept() >= 0) {
        cgiInit();
        run();
        destory();
    }
    return 0;
}
