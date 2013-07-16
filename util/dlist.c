#include "dlist.h"

void dlistInit(dlist *dlist,int (*match)(const void*,const void*),
                void (*destroy)(void *),void (*printf)(void *)){
    dlist->size = 0;
    dlist->match = match;
    dlist->destroy = destroy;
    dlist->printf = printf;
    dlist->head = NULL;
    dlist->tail = NULL;
}

int dlistRemove(dlist *dlist,dlistelmt *element,void **data){
    if (element == NULL || dlist->size == 0){
        return -1;
    }    
    if (NULL != data){
        *data = element->data;
    }
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
    void *data;
    while(dlist->size > 0){
        dlistRemove(dlist,dlist->head,(void **)&data);
        dlist->destroy(data);
    }
    memset(dlist,0,sizeof(dlist));
    free(dlist);
    return;
}

int dlistInsert(dlist *dlist,dlistelmt *element,const void *data){
    if (NULL == dlist){
        return -1;
    }    
    dlistelmt *newelmt = (dlistelmt *)malloc(sizeof(dlistelmt));
    if (NULL == newelmt){
        return -1;
    }
    newelmt->data = (void *)data;
    if (0 == dlist->size){
        dlist->head = newelmt;
        dlist->tail = newelmt;
    } else if (1 == dlist->size){
        if (NULL == element){
            dlist->head = newelmt;
            newelmt->next = dlist->tail;
            dlist->tail->prev = newelmt;
        } else {
            dlist->head->next = newelmt;
            newelmt->prev = dlist->head;
            dlist->tail = newelmt;
        }
    } else {
        if (NULL == element){
            dlist->head->prev = newelmt;
            newelmt->next = dlist->head;
            dlist->head = newelmt; 
        } else if (element == dlist->tail){
            dlist->tail->next = newelmt;
            newelmt->prev = dlist->tail;
            dlist->tail = newelmt;
        } else {
            newelmt->prev = element;
            newelmt->next = element->next;
            element->next->prev = newelmt;
            element->next = newelmt;
        } 
    }
    dlist->size++;
    return 0;
}

dlistelmt *dlistReturnElmt(dlist *dlist,int offset){
    if (NULL == dlist || 0 == dlist->size || 0 == offset){
        return NULL;    
    }            
    dlistelmt *element = NULL;
    int mark = 1;
    int offsetAbs = abs(offset);
    if (offset > 0){
        element = dlist->head;
        while (mark != offsetAbs){
            element = element->next;
            mark++;
        }
    } else {
        element = dlist->tail;
        while (mark != offsetAbs){
            element = element->prev;
            mark++;
        }
    }
    return element;
}

void dlistPrint(dlist *dlist){
    printf("-------dlist printf------\n");    
    if (NULL == dlist || 0 == dlist->size){
        printf("it's empty");    
    }      
    dlistelmt *element = dlist->head;
    printf("size: %d\n",dlist->size);
    int mark = 1;
    do {
        printf("element_%d: ",mark++);
        dlist->printf(element->data);
        printf("\n");
    } while ((element = element->next) && NULL != element);
    printf("-------------------------\n");    
}
