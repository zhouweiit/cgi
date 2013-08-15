#include "main.h"

void defaultMainHtml(){
    appendBody("<div style='text-align:center;margin-left:auto;'><h1>留言板</h1></div>");    
    dlist *list = NULL;
    selectAllArticle(&list);
    int length = list->size;
    appendBody("<form action='defaultSubmitMessage.c' method='post'>");
    appendBody("<table id=\"mytable\">");
    appendBody("<tr><th>留言信息</th><th>作者</th><th>留言时间</th></tr>");
    dlistelmt *elmt = list->tail;
    while(length-- > 0){
        dbinfo *info = (dbinfo *)elmt->data;
        appendBody("<tr><td class='row' width='70%'>");
        appendBody(info->value[2]);
        appendBody("</td><td td class='row' width='15%'>");
        appendBody(info->value[3]);
        appendBody("</td><td td class='row' width='15%'>");
        appendBody(info->value[4]);
        appendBody("</td></tr>");
        elmt = elmt->prev;
    }
    appendBody("<tr><td><input type='text' name='message' size=68/></td>");
    appendBody("<td><input type='text' name='name' size=8/></td>");
    appendBody("<td><input type='submit' value='留言'/></td></tr>");
    appendBody("</table>");
    appendBody("</form>");
    _dlistDestroy(list); 
}

void defaultSubmitMessage(){ 
    dlhashPrint(requestParamsPOST);
    //char *message = getParamsPOST("message");    
    //char *name = getParamsPOST("name");    
    //char *datetime = _DATETIME;
    //int result = insertArticle(name,message,datetime);
    //_free(datetime);
}
