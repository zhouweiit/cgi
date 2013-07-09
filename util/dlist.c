#include "dlist.h"


void dlistInit(dlist *dlist,int (*match)(const void*,const void*),void (*destroy)(void *data)){
    dlist->size = 0;
    dlist->match = match;
    dlist->destroy = destroy;
    dlist->head = NULL;
    dlist->tail = NULL;
}

int dlistRemove(dlist *dlist,dlistelmt *element,void *data){
    if (element == NULL || dlist->size == 0){
        return -1;
    }    
    data = element->data;
    if (element == dlist->head){
        dlist->head = element->next;
        if (dlist->size == 1){
            dlist->tail = NULL;    
        } else {
            element->next->prev = NULL;
        }        
    } else if (element == dlist->tail){
        dlist->tail = element->prev;
        if (dlist->size == 1){
            dlist->head = NULL;       
        } else {
           element->prev->next = NULL; 
        } 
    } else {
        element->prev->next = element->next;
        element->next->prev = element->prev;
    }
    free(element);
    dlist->size--;
    return 0;
}

void dlistDestroy(dlist *dlist){
    
}

int dlistInsertNext(dlist *dlist,dlistelmt *element,const void *data){
    
}

int dlistInsertPrev(dlist *dlist,dlistelmt *element,const void *data){

}
