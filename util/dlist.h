#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef __dlist_h
#define __dlist_h
#endif


typedef struct dlistelmt_{
   void *data;
   struct dlistelmt_ *prev;
   struct dlistelmt_ *next;
} dlistelmt;

typedef struct dlist_{
    int size;
    int (*match)(const void *,const void *);
    void (*destroy)(void *data);
    dlistelmt *head;
    dlistelmt *tail;
} dlist; 

extern void dlistInit(dlist *dlist,int (*match)(const void*,const void*),(*destroy)(void *data));
extern void dlistDestroy(dlist *dlist);
extern void dlistInsertNext(dlist *dlist,dlistelmt *element,const void *data);
extern void dlistInsertPrev(dlist *dlist,dlistemlt *element,const void *data);
extern void dlistRemove(dlist *dlist,listelmt *element,void *data);
