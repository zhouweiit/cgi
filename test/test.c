#include <stdio.h>
#include <stdlib.h>
#include "../util/dlist.h"

int test(int *a){
    
}

void dlistPrintfChar(void *data){
    printf("%s",(char *)data);
}

void dlistdestroy(void *data){
   free(data); 
}

int main(int argc,char **argv){
    dlist *testdlist = (dlist *)malloc(sizeof(dlist));
    void *match = NULL;
    void (*destroy)(void *) = dlistdestroy;
    void (*printf)(void *) = dlistPrintfChar;


    dlistInit(testdlist,match,destroy,printf);
    char *a = (char *)malloc(sizeof(char)*3);
    char *b = (char *)malloc(sizeof(char)*3);
    scanf("%s",a);
    scanf("%s",b);
    dlistInsert(testdlist,NULL,a);
    dlistInsert(testdlist,NULL,b);
    //dlistInsert(testdlist,NULL,"456");
    //dlistInsert(testdlist,NULL,"789");
    //printf("%d",testdlist->size);
    printDlist(testdlist);
    dlistDestroy(testdlist);
}
