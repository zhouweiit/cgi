#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcgi_stdio.h>

#ifndef __http_request_h
#define __http_request_h

#include "../util/dlist.h"
#include "../util/hash.h"
#include "../util/tools.h"
#include "server.h"


typedef struct httpData_{
    char *key;
    char *data;
} httpData;

/**
 * 通过HTTPGET提交的参数
 */
extern dlhash *requestParamsGET;

/**
 * 通过HTTPPOST提交的参数
 */
extern dlhash *requestParamsPOST;

/**
 * @TODO 根据httpData计算hash值
 * @param data httpData
 * @param buckets hash表的大小
 * @return int hash值
 * @author zhouwei 2013-7-21
 */
extern int hashHttpData(const void *data,int buckets);

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
extern void printHttpData(const void *data);

/**
 * @TODO 初始化请求
 * @author zhouwei 2013-7-20
 */
extern void initRequest();

/**
 * @TODO 销毁请求 
 * @return void
 * @author zhouwei 2013-7-21
 */
extern void destroyRequest();
#endif
