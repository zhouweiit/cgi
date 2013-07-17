#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

#ifndef __dlist_h
#include "../util/dlist.h"
#endif

#ifndef __hash_h
#include "../util/hash.h"
#endif

void dlistPrintfChar(void *data){
    printf("%s",(char *)data);
}

void dlistdestroy(void *data){
//        free(data);
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
    dlistDestroy(testdlist);
}

int match(const void *key1,const void *key2){
    charValue *key11 = (charValue *)key1;
    charValue *key22 = (charValue *)key2;
    char *strKey1 = key11->key;
    char *strKey2 = key22->key;
    return strcmp(strKey1,strKey2);
}

void hashTest(){
   dlhash *testdlhash = (dlhash *)malloc(sizeof(dlhash));    
   int (*hashStra)(const void *,int) = hashStr;
   int (*matcha)(const void *,const void *) = match;
   void (*destroya)(void *) = dlistdestroy;
   dlhashInit(testdlhash,10,matcha,hashStra,destroya);
charValue *v1 = (charValue *)malloc(sizeof(v1));v1->key = (char *)malloc(sizeof(char));*(v1->key)='a';
charValue *v2 = (charValue *)malloc(sizeof(v2));v2->key = (char *)malloc(sizeof(char));*(v2->key)='b';
charValue *v3 = (charValue *)malloc(sizeof(v3));v3->key = (char *)malloc(sizeof(char));*(v3->key)='c';
charValue *v4 = (charValue *)malloc(sizeof(v4));v4->key = (char *)malloc(sizeof(char));*(v4->key)='a';
    int esult = dlhashInsert(testdlhash,v1);
    int rsult = dlhashInsert(testdlhash,v2);
    int reult = dlhashInsert(testdlhash,v3);
    int reslt = dlhashInsert(testdlhash,v4);
    printf("%d",testdlhash->size);
    dlhashLookup(testdlhash,v3);
    dlhashDestroy(testdlhash);
}

int main(int argc,char **argv){
    hashTest();
//    dlistTest();
}
