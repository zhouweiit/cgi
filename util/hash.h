#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __util_hash_h
#define __util_hash_h
#endif

#ifndef __util_dlist_h
#include "dlist.h"
#endif

typedef struct dlhash_{
    int buckets;
    int (*hashkey)(const void *,int);
    int (*match)(const void *,const void *);
    void (*destroy)(void *);
    void (*print)(const void *);
    int size;
    dlist *dlists;
} dlhash;

/**
 * @TODO 字符串生成hashkey的函数
 * @param data 字符串
 * @param buckets桶的个数
 * @return hashkey
 * @author zhouwei 2013-7-11
 */
extern int hashStr(const void *data,int buckets);

/**
 * @TODO 哈希函数初始化
 * @param dlhash 已经分配好空间的哈希指针变量
 * @param match 匹配两个key是否相同的指针函数，需要返回0成功，其他失败
 * @hashkey hashkey生成函数
 * @destroy 元素析构函数
 * @return 0成功,-1失败
 * @author zhouwei 2013-7-11
 */
extern int dlhashInit(dlhash *dlhash,int buckets,int (*match)(const void *,const void *),
                       int (*hashkey)(const void *,int), void (*destroy)(void *),void (*print)(const void *));

/**
 * @TODO 根据key移除一个元素
 * @param dlhash 哈希表
 * @param key 哈希的key
 * @param data 返回的数据指针
 * @return 0成功-1失败
 * @author zhouwei 2013-7-12
 */
extern int dlhashRemove(dlhash *dlhash,const void *key,void **data);

/**
 * @TODO 哈希的析构函数
 * @param dlhash 哈希表
 * @return 0成功-1失败
 * @author zhouwei 2013-7-12
 */
extern void dlhashDestroy(dlhash *dlhash);

/**
 * @TODO 根据传进来的元素获取数据
 * @param dlhash 哈希表
 * @param key 哈希元素
 * @return 哈希元素
 * @author zhouwei 2013-7-13
 */
extern void *dlhashLookup(const dlhash *dlhash,const void *key);

/**
 * @TODO 插入新的元素进入哈希表
 * @param dlhash 哈希表
 * @param data 哈希元素
 * @return 0成功-1失败
 * @author zhouwei 2013-7-14
 */
extern int dlhashInsert(dlhash *dlhash,const void *data); 

/**
 * @TODO 打印当前的hash表
 * @param dlhash 哈希表
 * @return void
 * @author zhouwei 2013-7-17
 */
extern void dlhashPrint(const dlhash *dlhash);
