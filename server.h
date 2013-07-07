#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcgi_stdio.h>

#ifndef __tools_h
#include "tools.h"
#endif

#ifndef __server_h
#define __server_h
#endif

#define getenv(name) (char *)getenv(name)

typedef enum {GET,POST,PUT,DELETE} method;
typedef struct{
    int contentLength;
    char *queryString;    
    method requestMethod;
    char *requestMethodStr;
    char *contentType;
    char *scriptFileName;
    char *scriptName;
    char *requestUri;
    char *documentUri;
    char *serverProtocol;
    char *remoteAddr;
    char *remotePort;
    char *serverAddr;
    char *serverPort;
    char *serverName;
    char *scream;
} server;

extern int serverInit();
extern server SERVER;
