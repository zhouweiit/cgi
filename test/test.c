#include "test.h"

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
   void (*printfa)(void *) = dlistPrintfChar;
   dlhashInit(testdlhash,10,matcha,hashStra,destroya,printfa);
charValue *v1 = (charValue *)malloc(sizeof(v1));v1->key = (char *)malloc(sizeof(char));*(v1->key)='a';
charValue *v2 = (charValue *)malloc(sizeof(v2));v2->key = (char *)malloc(sizeof(char));*(v2->key)='b';
charValue *v3 = (charValue *)malloc(sizeof(v3));v3->key = (char *)malloc(sizeof(char));*(v3->key)='c';
charValue *v4 = (charValue *)malloc(sizeof(v4));v4->key = (char *)malloc(sizeof(char));*(v4->key)='f';
charValue *v5 = (charValue *)malloc(sizeof(v5));v5->key = (char *)malloc(sizeof(char));*(v5->key)='v';
    dlhashInsert(testdlhash,v1);
    dlhashInsert(testdlhash,v2);
    dlhashInsert(testdlhash,v3);
    dlhashInsert(testdlhash,v4);
    dlhashInsert(testdlhash,v5);
    printf("%d",testdlhash->size);
    charValue *v11=dlhashLookup(testdlhash,v4);
    printf("%s",v11->key);
    dlhashPrint(testdlhash);
    dlhashDestroy(testdlhash);
}

int main(int argc,char **argv){
    char *a = "123&456&789";
    dlist *testdlist = (dlist *)malloc(sizeof(dlist));
    void *match = NULL;
    void (*destroy)(void *) = dlistdestroy;
    void (*printf)(void *) = dlistPrintfChar;
    dlistInit(testdlist,match,destroy,printf);
    explode(a,'&',testdlist);
    dlistPrint(testdlist);
}
