#include "http.h"

dlhash requestParamsGET;
dlhash requestParamsPOST;

void destroyHttpData(void *data){
    httpData *dataDestroy = (httpData *)data;
    free(dataDestroy->key);
    free(dataDestroy->data);
    dataDestroy->key = NULL;
    dataDestroy->data = NULL;
} 

int matchHttpData(const void *httpData1,const void *httpData2){
    httpData *data1 = (httpData *)httpData1;
    httpData *data2 = (httpData *)httpData2;
    return strcmp(data1->key,data2->key);
}

void printHttpData(const void *data){
    httpData *httpData = (httpData *)data;
    printf("key:%s  data:%s",httpData->key,httpData->data);
}

void initRequestParams(){
    initGetParams();
    initPostParams();
}

static void initGetParams(){
    if (strlen(SERVER.queryString) > 0){
    }
}

static void initPostParams(){
    if (SERVER.contentLength > 0){
    }
}

static void initParams(char *paramsStr){
    dlist *params = (dlist *)malloc(sizeof(dlist));
    explode(paramsStr,'&',dlist);    
}

