#include "http.h"

void httpInit(){
    serverInit();
    initRequestParams();
}

void httpDestroy(){
    destoryParams();        
}

char *getParamsGET(char *key){
    httpData data = {key,NULL};
    return ((httpData *)dlhashLookup(requestParamsGET,&data))->data;
}

char *getParamsPOST(char *key){
    httpData data = {key,NULL};
    return ((httpData *)dlhashLookup(requestParamsPOST,&data))->data;
}
