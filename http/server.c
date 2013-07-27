#include "server.h"

server *SERVER;

static void contentLength(){
    char *leng = getenv("CONTENT_LENGTH"); 
    if (NULL != leng){
        SERVER->contentLength = strtol(leng,NULL,10);
    } else {
        SERVER->contentLength = 0;
    }
}

static method requestMethod(){
    char *requestMethod = getenv("REQUEST_METHOD");
    char *methodUp = NULL;
    if (NULL != requestMethod){
        methodUp = strupr(requestMethod);   
        SERVER->requestMethodStr = methodUp; 
        if (strcmp(methodUp,"GET") == 0){
            SERVER->requestMethod = GET; 
        } else if (strcmp(methodUp,"POST") == 0){
            SERVER->requestMethod = POST;
        } else if (strcmp(methodUp,"PUT") == 0){
            SERVER->requestMethod = PUT;
        } else if (strcmp(methodUp,"DELETE") == 0){
            SERVER->requestMethod = DELETE;
        } else {
            SERVER->requestMethod = -1;
        }
    } 
}

static void queryString(){
    SERVER->queryString = getenv("QUERY_STRING");
}

static void contentType(){
    SERVER->contentType = getenv("CONTENT_TYPE");    
}

static void scriptFileName(){
    SERVER->scriptFileName = getenv("SCRIPT_FILENAME");    
}

static void scriptName(){
    SERVER->scriptName = getenv("SCRIPT_NAME");
}

static void requestUri(){
    SERVER->requestUri = getenv("REQUEST_URI");
}

static void serverProtocol(){
    SERVER->serverProtocol = getenv("SERVER_PROTOCOL");    
}

static void remoteAddr(){
    SERVER->remoteAddr = getenv("REMOTE_ADDR");
}

static void remotePort(){
    SERVER->remotePort = getenv("REMOTE_PORT");    
}

static void serverAddr(){
    SERVER->serverAddr = getenv("SERVER_ADDR");
}

static void serverPort(){
    SERVER->serverPort = getenv("SERVER_PORT");
}

static void serverName(){
    SERVER->serverName = getenv("SERVER_NAME");
}

static void documentUri(){
    SERVER->documentUri = getenv("DOCUMENT_URI");    
}

static void scream(){
    if (SERVER->contentLength > 0){
        char *scream = (char *)calloc(SERVER->contentLength,sizeof(char));
        int ch,i = 0;
        SERVER->scream = scream;
        for (i = 0;i < SERVER->contentLength; i++){
            if ((ch = getchar()) >= 0){
                *scream = ch;
                scream++;
            } else {
                break; 
            }    
        }
    }
}

void initServer(){ 
    SERVER = (server *) malloc(sizeof(server));
    contentLength();
    requestMethod();
    queryString();
    contentType();
    scriptFileName();
    scriptName();
    requestUri();
    serverProtocol();
    remoteAddr();
    serverAddr();
    serverPort();
    serverName();
    scream();
    documentUri();
}

void destroyServer(){
    if (SERVER->contentLength > 0 && NULL != SERVER->scream){
        free(SERVER->scream);
        SERVER->scream = NULL;
    }
    memset(SERVER,0,sizeof(SERVER));
    SERVER = NULL;
}
