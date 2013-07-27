#include "../basic.h"

#ifndef __http_response_h
#define __http_response_h
#include "../util/dlist.h"

extern dlist *httpHead;

extern dlist *head;

extern dlist *body;

/**
 * @TODO 输出HTML
 * @return void
 * @author zhouwei 2013-7-22
 */
extern void sendHtml();

/**
 * @TODO 销毁响应
 * @return void
 * @author zhouwei 2013-7-22
 */
extern void destroyResponse();

/**
 * @TODO 添加http的头信息
 * @return void
 * @author zhouwei 2013-7-27
 */
extern void appentHttpHead(char *httpHead);

/**
 * @TODO 添加头html
 * @return void
 * @author zhouwei 2013-7-22
 */
extern void appendHead(char *head);

/**
 * @TODO 添加body的html
 * @return void
 * @author zhouwei 2013-7-22
 */
extern void appendBody(char *body);

/**
 * @TODO 初始化response
 * @return void
 * @author zhouwei 2013-7-22
 */
extern void initResponse();
#endif
