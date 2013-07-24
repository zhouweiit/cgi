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
    data->actionFunction = NULL
}

static void initAction(){
    dlhash *action = (dlhash *)malloc(sizeof(dlhash));
    int (*hashKey)(const void *,int) = hashStr;
    int (*match)(const void *,const void *) = matchAction;
    void (*destroy)(void *) = destroyAction;
    dlhashInit(action,30,match,hashKey,destroy,NULL);
}

static void actionInsert(char *actionKey,void (*actionFunction)){
    char *key = (char *)malloc((strlen(actionKey) + 1) * sizeof(char));
    strcpy(key,actionKey);
    actionData *data = (actionData *)malloc(sizeof(actionData));
    data->key = key;
    data->actionFunction = actionFunction;
    dlhashInsert(action,data);
}

static void loadAction(){
    void (*adminTestHello) = adminTestHello;
    actionInsert("adminTestHello",adminTestHello);
}

void initRoute(){
    initAction();
    loadAction();
}

void route(char *scriptName){
     
}
