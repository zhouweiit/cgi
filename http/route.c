#include "route.h"

dlhash *action;

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
    int (*hashKey)(const void *,int) = hashStr;
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
    void (*adminTestHelloAction)() = adminTestHello;
    actionInsert("/adminTestHello.c",adminTestHelloAction);
}

void initRoute(){
    initAction();
    loadAction();
}

void route(char *scriptName){
    actionData data = {scriptName,NULL};
    actionData *actionData = dlhashLookup(action,&data);
    dlhashPrint(action);
}
