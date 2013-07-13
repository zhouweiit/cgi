#include "hash.h"

unsigned int hashStr(const void *key,int buckets){
    const char *ptr = (char *)key;
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

int dlhashInit(dlhash *dlhash,int buckets,int (*match)(const void *,const void *),
                    int (*hashkey)(const void *,int), void (*destroy)(void *)){
    dlhash->buckets = buckets;
    dlhash->size = 0;
    dlhash->match = match;
    dlhash->hashkey = hashkey;
    dlhash->destroy = destroy;
    dlhash->dlist = (dlist *)malloc(buckets*(sizeof(dlist)));
    if (NULL == dlhash->dlist){
        return -1;    
    }
    int i = 0;
    while (i < buckets){
        dlistInit(&dlhash->dlist[i++],match,destroy,NULL);
    }
    return 0;
}


