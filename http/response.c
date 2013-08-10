#include "response.h"

dlist *httpHead;

dlist *head;

dlist *body;

static void destroyHtml(void *html){
    free(html);
    html = NULL;
}

static void printHttpData(const void *data){
    char *dataTmp= (char *)data;
    printf("data:%s",dataTmp);
}

static void sendHttpHead(){
    if (httpHead->size > 0){
        dlistelmt *headelmt = httpHead->tail;    
        do{
            printf("%s\r\n",(char *)headelmt->data); 
        } while ((headelmt = headelmt->prev) != NULL);
    }
    printf("\r\n");
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
    sendHttpHead();
    printf("<html>\n");
    sendHead();
    sendBody();
    printf("</html>");
}

void destroyResponse(){
    _dlistDestroy(httpHead);
    _dlistDestroy(head);
    _dlistDestroy(body);
}

void appendHttpHead(char *HttpHeadTmp){
    char *HttpHeadAdd = (char *)malloc((strlen(HttpHeadTmp) + 1)* sizeof(char));
    strcpy(HttpHeadAdd,HttpHeadTmp);
    dlistInsert(httpHead,NULL,HttpHeadAdd);
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
    httpHead = (dlist *)malloc(sizeof(dlist));
    head = (dlist *)malloc(sizeof(dlist));
    body = (dlist *)malloc(sizeof(dlist));
    dlistInit(httpHead,NULL,destroy,printHttpData);
    dlistInit(head,NULL,destroy,printHttpData);
    dlistInit(body,NULL,destroy,printHttpData);
}
