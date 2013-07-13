#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

#ifndef __hash_h
#define __hash_h
#endif

typedef struct dlhash_{
    int buckets;
    int (*hashkey)(const void *,int);
    int (*match)(const void *,const void *);
    void (*destroy)(void *);
    int size;
    dlist *dlist;
} dlhash;

extern unsigned int hashStr(const void *key,int buckets);
extern int dlhashInit(dlhash *dlhash,int buckets,int (*match)(const void *,const void *),
                        int (*hashkey)(const void *,int), void (*destroy)(void *));
extern int dlhashRemove(dlhash *dlhash,const void *key,void **data);
extern int dlhashDestroy(dlhash *dlhash);
extern void *dlhashLookup(const dlhash *dlhash,const void *data);
extern int dlhashInsert(dlhash *dlhash,const void *data); 

