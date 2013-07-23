#include "http.h"

void httpInit(){
    initServer();
    initRequest();
    initResponse();
}

void httpDestroy(){
    destroyRequest();
    destroyResponse();
}

char *getParamsGET(char *key){
    httpData data = {key,NULL};
    return ((httpData *)dlhashLookup(requestParamsGET,&data))->data;
}

char *getParamsPOST(char *key){
    httpData data = {key,NULL};
    return ((httpData *)dlhashLookup(requestParamsPOST,&data))->data;
}
