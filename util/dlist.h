#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef __dlist_h
#define __dlist_h
#endif


typedef struct dlistelmt_{
   void *data;
   struct dlistelmt_ *prev;
   struct dlistelmt_ *next;
} dlistelmt;

typedef struct dlist_{
    int size;
    int (*match)(const void *,const void *);
    void (*destroy)(void *data);
    void (*printf)(void *data);
    dlistelmt *head;
    dlistelmt *tail;
} dlist; 


/**
 * @TODO 双向链表初始化,需要提前申请好内存空间
 * @param dlist 已经初始化好的双向链表
 * @param match 匹配链表中的某元素是否符合的指针函数
 * @param destory 用来销毁链表中的元素的指针函数
 * @param printf 用来打印链表中的元素的指针函数
 * @return void
 * @author zhouwei 2013-7-9
 */
extern void dlistInit(dlist *dlist,int (*match)(const void*,const void*),
                        void (*destroy)(void *data),void (*printf)(void *));
/**
 * @TODO 销毁一个双向链表，销毁其中每一个元素与链表本省
 * @param dlist 一个双向链表指针
 * @return void
 * @author zhouwei 2013-7-9
 */
extern void dlistDestroy(dlist *dlist);

/**
 * @TODO 向双向链表中插入一个元素
 * @param dlist 一个已经初始化好的双向链表
 * @param element 往哪个元素之后插入元素，若element为NULL，则插入在链表的头
 * @param data 要插入元素的信息
 * @return 0插入成功，-1插入失败
 * @author zhouwei 2013-7-10
 */
extern int dlistInsert(dlist *dlist,dlistelmt *element,const void *data);

/**
 * @TODO 删除一个元素，并且把元素的信息返回值data指针
 * @param dlist 一个已经初始化好的双向链表
 * @param element 需要删除的元素
 * @param data 返回的元素数据指针
 * @return 0删除成功,-1删除失败
 * @author zhouwei 2013-7-10
 */
extern int dlistRemove(dlist *dlist,dlistelmt *element,void **data);

/**
 * @TODO 打印链表
 * @param dlist 一个已经初始化好的双向链表
 * @return void
 * @author zhouwei 2013-7-11
 */
extern void printDlist(dlist *dlist);
