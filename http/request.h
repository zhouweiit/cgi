#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __http_request_h
#define __http_request_h
#endif

#ifndef __util_dlist_h
#include "../util/dlist.h"
#endif

#ifndef __util_hash_h
#include "../util/hash.h"
#endif

#ifdef __util_tools_h
#include "../util/tools.h"
#endif

typedef struct httpData_{
    char *key;
    char *data
} httpData;

/**
 * 通过HTTPGET提交的参数
 */
extern dlhash requestParamsGET;

/**
 * 通过HTTPPOST提交的参数
 */
extern dlhash requestParamsPOST;

/**
 * @TODO httpData希构函数
 * @param data 类型为httpData的数据
 * @return void
 * @author zhouwei 2013-7-20
 */
extern void destroyHttpData(void *data);

/**
 * @TODO httpData的对比函数
 * @param data1 需要对比的httpData的数据
 * @param data2 需要对比的httpData的数据
 * @return void 0 相等 其他 不等
 * @author zhouwei 2013-7-20
 */
extern int matchHttpData(const void *data1,const void *data2);

/**
 * @TODO 打印httpData
 * @param data httpData
 * @return void
 * @author zhouwei 2013-7-20
 */
extern void printHttpData(const void data);

/**
 * @TODO 初始化请求参数
 * @return int 0成功 其他失败
 * @author zhouwei 2013-7-20
 */
extern void initRequestParams();
