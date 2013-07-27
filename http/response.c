#include "response.h"

dlist *head;

dlist *body;

static void destroyHtml(void *html){
    free(html);
    html = NULL;
}

static void sendHead(){
    printf("<head>\n");
    if (head->size > 0){
        dlistelmt *headelmt = head->tail;    
        do{
           printf("%s\n",(char *)headelmt->data); 
        } while ((headelmt = headelmt->prev) != NULL);
    }
    printf("</head>\n");
}

static void sendBody(){
    printf("<body>\n");
    if (body->size > 0){
        dlistelmt *bodyelmt = body->tail;    
        do{
            printf("%s\n",(char *)bodyelmt->data); 
        } while ((bodyelmt = bodyelmt->prev) != NULL);
    }
    printf("</body>\n");
}

void sendHtml(){
    printf("<html>");
    sendHead();
    sendBody();
    printf("</html>");
}

void destroyResponse(){
    _dlistDestroy(head);
    _dlistDestroy(body);
}

void appendHead(char *headTmp){
    char *headAdd = (char *)malloc((strlen(headTmp) + 1)* sizeof(char));
    strcpy(headAdd,headTmp);
    dlistInsert(head,NULL,headAdd);
}

void appendBody(char *bodyTmp){
    char *bodyAdd = (char *)malloc((strlen(bodyTmp) + 1)* sizeof(char));
    strcpy(bodyAdd,bodyTmp);
    dlistInsert(body,NULL,bodyAdd);
}

void initResponse(){
    void (*destroy)(void *) = destroyHtml;
    head = (dlist *)malloc(sizeof(dlist));
    body = (dlist *)malloc(sizeof(dlist));
    dlistInit(head,NULL,destroy,NULL);
    dlistInit(body,NULL,destroy,NULL);
}
