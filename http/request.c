#include "request.h"

dlhash *requestParamsGET;
dlhash *requestParamsPOST;

int hashHttpData(const void *data,int buckets){
    httpData *dataTmp = (httpData *)data; 
    const char *ptr = dataTmp->key; 
    unsigned int val = 0;
    while (*ptr != '\0'){
        unsigned int tmp;
        val = (val << 4) + (*ptr);
        if (tmp = (val & 0xf0000000)){
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        ptr++;
    }
    return val % buckets;
}

void destroyHttpData(void *data){
    httpData *dataDestroy = (httpData *)data;
    free(dataDestroy->key);
    free(dataDestroy->data);
    dataDestroy->key = NULL;
    dataDestroy->data = NULL;
    free(data);
} 

int matchHttpData(const void *httpData1,const void *httpData2){
    httpData *data1 = (httpData *)httpData1;
    httpData *data2 = (httpData *)httpData2;
    return strcmp(data1->key,data2->key);
}

void printHttpData(const void *data){
    httpData *dataTmp= (httpData *)data;
    printf("key:%s  data:%s",dataTmp->key,dataTmp->data);
}

static void paramsTmpDestroy(void *data){
    free(data);
    data = NULL;
}

static void initParams(char *paramsStr,dlhash *dlhash){
    void (*paramTmpDestroy) = paramsTmpDestroy;
    dlist *params = (dlist *)malloc(sizeof(dlist));
    dlistInit(params,NULL,paramTmpDestroy,NULL);
    explode(paramsStr,'&',params);    
    dlistelmt *element = params->head;
    do {
        dlist *paramsTmp = (dlist *)malloc(sizeof(dlist));
        dlistInit(paramsTmp,NULL,paramTmpDestroy,NULL);
        explode(element->data,'=',paramsTmp);
        httpData *value = (httpData *)malloc(sizeof(httpData));
        char *key  = (char *)malloc((strlen(paramsTmp->tail->data) + 1)*sizeof(char));
        char *data = (char *)malloc((strlen(paramsTmp->tail->data) + 1)*sizeof(char));
        strcpy(key,paramsTmp->tail->data);
        strcpy(data,paramsTmp->head->data);
        value->key  = urldecode(key);
        value->data = urldecode(data);
        dlhashInsert(dlhash,value);
        dlistDestroy(paramsTmp);
        free(paramsTmp);
    } while ((element = element->next) != NULL);
    dlistDestroy(params);
    free(params);
}

static void initParamsHash(dlhash *paramsHash){
    int (*hashKey)(const void *,int) = hashHttpData;
    int (*match)(const void *,const void *) = matchHttpData;
    void (*destroy)(void *) = destroyHttpData;
    void (*print)(const void *) = printHttpData;
    dlhashInit(paramsHash,20,match,hashKey,destroy,print);
}

static void initGetParams(){
    if (strlen(SERVER.queryString) > 0){
        requestParamsGET = (dlhash *)malloc(sizeof(dlhash));    
        initParamsHash(requestParamsGET);
        initParams(SERVER.queryString,requestParamsGET);
    }
}

static void initPostParams(){
    if (SERVER.contentLength > 0){
        requestParamsPOST = (dlhash *)malloc(sizeof(dlhash));    
        initParamsHash(requestParamsPOST);
        initParams(SERVER.scream,requestParamsPOST);
    }
}

static void initRequestParams(){
    initGetParams();
    initPostParams();
}

static void destroyParams(){
    dlhashDestroy(requestParamsGET);    
    dlhashDestroy(requestParamsPOST);    
    free(requestParamsGET);
    free(requestParamsPOST);
    requestParamsGET  = NULL;
    requestParamsPOST = NULL;
}

void initRequest(){
    initRequestParams();    
}

void destroyRequest(){
    destroyParams();
}
