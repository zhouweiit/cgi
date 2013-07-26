#include <stdio.h>
#include <fcgi_stdio.h>

#ifndef __http_route_h
#define __http_route_h
#endif

#ifndef __util_hash_h
#include "../util/hash.h"
#endif

#ifndef __admin_test_h
#include "../admin/test.h"
#endif

#ifndef __http_server_h
#include "server.h"
#endif

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
