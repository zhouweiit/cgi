#include "../basic.h"

#ifndef __http_route_h
#define __http_route_h

#include "../util/hash.h"
#include "../admin/test.h"
#include "../default/main.h"
#include "response.h"
#include "server.h"


typedef struct actionData_{
    char *key;
    void (*actionFunction)();
} actionData;

extern dlhash *action;

/**
 * @TODO 根据script_name路由到特定的方法
 * @param sriptName 
 * @return void
 * @author zhouwei 2013-7-24
 */
extern void route(char *scriptName);

/**
 * @TODO 初始化路由器
 * @return void
 * @author zhouwei 2013-7-24
 */
extern void initRoute();
#endif
