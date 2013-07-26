#include "cgi.h"

static void cgiInit(){
    httpInit();
}

static void destory(){
    httpDestroy(); 
}

static int scriptUriCheck(){
    return countChar(SERVER.scriptName,'/'); 
}

static void run(){
    printf( "Status: 200 OK\r\n"
            "Test-head-1:test\r\n"
            "Content-type: text/html\r\n"
            "Test-head-2:test\r\n"
            "\r\n"
            "");
    route(SERVER.scriptName);
}

int main (){
    while (FCGI_Accept() >= 0) {
        cgiInit();
        
        run();
       // printf("%s<br />",SERVER.scriptName);
       // printf("%s<br />",SERVER.documentUri);
       // printf("%s<br />",SERVER.scriptFileName);
       // printf("%s<br />",SERVER.queryString);
       // printf("%s<br />",SERVER.requestUri);
       // destory();
    }
    return 0;
}
