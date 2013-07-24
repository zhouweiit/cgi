#include <stdio.h>

#ifndef __http_http_h
#define __http_http_h
#endif

#ifndef __http_server_h
#include "server.h"
#endif

#ifndef __http_request_h
#include "request.h"
#endif

#ifndef __util_hash_h
#include "../util/hash.h"
#endif

#ifndef __http_route_h
#include "route.h"
#endif

/**
 * @TODO http_init
 * @return void
 * @author zhouwei 2013-7-21
 */
extern void httpInit();

/**
 * @TODO 根据key获取get中value
 * @return 值
 * @author zhouwei 2013-7-21
 */
extern char *getParamsGET(char *key);

/**
 * @TODO 根据key获取post中value
 * @return 值
 * @author zhouwei 2013-7-21
 */
extern char *getParamsPOST(char *key);

/**
 * @TODO 当请求结束时候，销毁http资源
 * @return void
 * @author zhouwei 2013-7-21
 */
extern void httpDestroy();
