#include "hash.h"

int hashStr(const void *data,int buckets){
    const charValue *str = (charValue *)data;
    const char *ptr = (char *)str->key;
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
    dlhash->dlists = (dlist *)malloc(buckets*(sizeof(dlist)));
    if (NULL == dlhash->dlists){
        return -1;    
    }
    int i = 0;
    while (i < buckets){
        dlistInit(&dlhash->dlists[i++],match,destroy,destroy);
    }
    return 0;
}

void dlhashDestroy(dlhash *dlhash){
    if (NULL == dlhash){
        return;    
    }     
    while (dlhash->buckets > 0){
        dlistDestroy(&dlhash->dlists[--dlhash->buckets]);
    }
    memset(dlhash,0,sizeof(dlhash));
}

int dlhashRemove(dlhash *dlhash,const void *key,void **data){
    if (NULL == dlhash){
        return -1;    
    }
    int bucket = dlhash->hashkey(key,dlhash->buckets);    
    dlist *dlist = &dlhash->dlists[bucket];
    dlistelmt *element = dlist->head;
    if (NULL == element || 0 == dlist->size){
        return -1;    
    }
    do{
        if (0 == dlhash->match(key,element->data)){
            if (0 == dlistRemove(dlist,element,data)){
                dlhash->size--;
                return 0;   
            } else {
                return -1;        
            }           
        }
    } while (NULL != (element = element->next));
    return -1;
}


int dlhashInsert(dlhash *dlhash,const void *data){
    if (NULL == dlhash || NULL == data){
        return -1;    
    }
    int bucket = dlhash->hashkey(data,dlhash->buckets);
    dlist *dlist = &dlhash->dlists[bucket];
    dlhashRemove(dlhash,data,NULL);
    if (0 == dlistInsert(dlist,NULL,data)){
        dlhash->size++;
    }
    return -1;
}

void *dlhashLookup(const dlhash *dlhash,const void *data){
    if (NULL == dlhash || NULL == data){
        return NULL;    
    }
    int bucket = dlhash->hashkey(data,dlhash->buckets);    
    dlist *dlist = &dlhash->dlists[bucket];
    dlistelmt *element = dlist->head;
    if (NULL == element || 0 == dlist->size){
        return NULL;    
    }
    do{
        if (0 == dlhash->match(data,element->data)){
            return element->data;
        }
    } while (NULL != (element = element->next));
    return NULL;
}

