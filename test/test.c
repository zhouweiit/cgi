#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __dlist_h
#include "../util/dlist.h"
#endif

#ifndef __hash_h
#include "../util/hash.h"
#endif


typedef struct charValue_{
    char *key;
    void *data;
} charValue;

void dlistPrintfChar(void *data){
    printf("%s",(char *)data);
}

void dlistdestroy(void *data){
    free(data);
}

int dlistTest(){
    dlist *testdlist = (dlist *)malloc(sizeof(dlist));
    void *match = NULL;
    void (*destroy)(void *) = dlistdestroy;
    void (*printf)(void *) = dlistPrintfChar;


    dlistInit(testdlist,match,destroy,printf);
    char *a = (char *)malloc(sizeof(char)*3);
    char *b = (char *)malloc(sizeof(char)*3);
    char *c = (char *)malloc(sizeof(char)*3);
    char *d = (char *)malloc(sizeof(char)*3);
    char *e = (char *)malloc(sizeof(char)*3);
    scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);
    scanf("%s",d);
    scanf("%s",e);
    dlistInsert(testdlist,NULL,a);
    dlistInsert(testdlist,NULL,b);
    dlistInsert(testdlist,NULL,c);
    dlistInsert(testdlist,NULL,d);
    dlistInsert(testdlist,NULL,e);
    dlistelmt *testemlt = dlistReturnElmt(testdlist,4);
    dlistPrintfChar(testemlt->data);
    char *f = (char *)malloc(sizeof(char)*3);
    scanf("%s",f);
    dlistInsert(testdlist,testemlt,f);
    dlistPrint(testdlist);
    void *data = NULL;
    dlistRemove(testdlist,testemlt,&data);
    dlistPrintfChar(data);
    dlistPrint(testdlist);
}

int match(void *key1,void *key2){
    charValue *key11 = (charValue *)key1;
    charValue *key22 = (charValue *)key2;
    char *strKey1 = key11->key;
    char *strKey2 = key22->key;
    return strcmp(strKey1,strKey2);
}

void hashTest(){
   dlhash *testdlhash = (dlhash *)malloc(sizeof(dlhash));    
   int (*hashStr)(const void *,int) = hashStr;
   dlhashInit(testdlhash,10,NULL,hashStr,NULL);
}

int main(int argc,char **argv){
    hashTest();
}
