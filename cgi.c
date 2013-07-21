#include "cgi.h"


static void cgiInit(){
    httpInit();
}

static void destory(){
    httpDestroy(); 
}

int main (){
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n""\r\n""");
        cgiInit();
        destory();
    }
    return 0;
}
