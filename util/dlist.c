#include "dlist.h"


void dlistInit(dlist *dlist,int (*match)(const void*,const void*),(*destroy)(void *data)){
    dlist->size = 0;
    dlist->match = match;
    dllis->destroy = destroy;
    dlist->head = NULL;
    dlist->tail = NULL;
}

void dlistRemove(dlist *dlist,listelmt *element,void **data){
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
    list->size--;
    return 0;
}

void dlistDestroy(dlist *dlist){
    
}

void dlistInsertNext(dlist *dlist,dlistelmt *element,const void *data){
    
}

void dlistInsertPrev(dlist *dlist,dlistemlt *element,const void *data){

}
