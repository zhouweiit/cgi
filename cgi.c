#include "cgi.h"


static void cgiInit(){
    httpInit();
}

int main (){
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n""\r\n""<title>FastCGI</title>");
        cgiInit();
    }
    return 0;
}
