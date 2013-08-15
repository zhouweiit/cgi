#include "../basic.h"

#ifndef __http_http_h
#define __http_http_h

#include "../util/hash.h"
#include "server.h"
#include "request.h"
#include "route.h"

/**
 * @TODO http_init
 * @return void
 * @author zhouwei 2013-7-21
 */
extern void httpInit();

/**
 * @TODO 当请求结束时候，销毁http资源
 * @return void
 * @author zhouwei 2013-7-21
 */
extern void httpDestroy();
#endif
