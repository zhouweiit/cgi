#include "main.h"

void defaultMainHtml(){
    appendBody("<div style='text-align:center; margin-left:auto;'><h3>留言板主页</h3></div>");    
    dlist *list = NULL;
    selectAllArticle(&list);
    dlistPrint(list);
}
