#include "route.h"

dlhash *action;

static int hashAction(const void *data,int buckets){
    const actionData *dataTmp = (actionData *)data; 
    char *ptr = dataTmp->key;
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

static int matchAction(const void *key1,const void *key2){
    actionData *data1 = (actionData *)key1;
    actionData *data2 = (actionData *)key2;
    return strcmp(data1->key,data2->key);
}

static void destroyAction(void *dataTmp){
    actionData *data = (actionData *)dataTmp;
    free(data->key);
    free(data->actionFunction);
    data->key = NULL;
    data->actionFunction = NULL;
}

static void printAction(const void *data){
    actionData *dataTmp = (actionData *)data;
    printf("%s",dataTmp->key);
}

static void initAction(){
    action = (dlhash *)malloc(sizeof(dlhash));
    int (*hashKey)(const void *,int) = hashAction;
    int (*match)(const void *,const void *) = matchAction;
    void (*destroy)(void *) = destroyAction;
    void (*print)(const void *) = printAction;
    dlhashInit(action,30,match,hashKey,destroy,print);
}

static void actionInsert(char *actionKey,void (*actionFunction)()){
    char *key = (char *)malloc((strlen(actionKey) + 1) * sizeof(char));
    strcpy(key,actionKey);
    actionData *data = (actionData *)malloc(sizeof(actionData));
    data->key = key;
    data->actionFunction = actionFunction;
    dlhashInsert(action,data);
}

static void loadAction(){
    actionInsert("/adminTestHello.c",adminTestHello);
    actionInsert("/defaultMainHtml.c",defaultMainHtml);
    actionInsert("/defaultSubmitMessage.c",defaultSubmitMessage);
}

void initRoute(){
    initAction();
    loadAction();
}

void route(char *scriptName){
    actionData data = {scriptName,NULL};
    actionData *actionFun = (actionData *)dlhashLookup(action,&data);
    if (NULL == actionFun){
        appendHttpHead("Status: 302 OK");
        appendHttpHead("Location: /404.html");
    } else {
        actionFun->actionFunction();
    }
}
