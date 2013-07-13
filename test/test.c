#include <stdio.h>
#include <stdlib.h>
#include "../util/dlist.h"

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

int main(int argc,char **argv){
    dlistTest();
}
