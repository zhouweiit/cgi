#include <stdio.h>
#include <string.h>

#ifndef __http_response_h
#define __http_response_h
#endif

#ifndef _cgi_debug_
#include <fcgi_stdio.h>
#endif

char *html = "\
    <html>\
        <head>\
            <meta content=\"text/html; charset=utf-8\" http-equiv=\"Content-Type\">\
            <title>用c编写基于fastcgi的cgi</title>\
        </head>\
        <body>\
        </body>\
    </html>";


