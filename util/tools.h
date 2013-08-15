#include "../basic.h"

#ifndef __util_tools_h
#define __util_tools_h

#include "dlist.h"

#define _YEAR getDateByType(0)
#define _MON getDateByType(1)
#define _DAY getDateByType(2)
#define _HOUR getDateByType(3)
#define _MIN getDateByType(4)
#define _SEC getDateByType(5) 
#define _DATETIME getDatetime()
#define _DATET getDate()

typedef struct pstruct_{
    int length;
    int offset;
    void *data;
    struct pstruct *pst;
    void (*destroy)(void *);
} pstruct;

/**
 * @TODO 大写转换
 * @param str 字符串
 * @return 字符串指针 
 * @author zhouwei 2013-7-20
 */
extern char *strupr(char *str);

/**
 * @TODO urldecode
 * @param p 字符串指针
 * @return 
 * @author zhouwei 2013-7-20
 */
extern char *urldecode(char *p);

/**
 * @TODO 根据字符分割字符串
 * @param string 待分割的字符串
 * @param explode 分割字符
 * @param dlist 双向链表
 * @return int 0成功 1失败
 * @author zhouwei 2013-7-20
 */
int explode(char *string,char explode,dlist *dlist);

/**
 * @TODO 查找字符出现的次数
 * @param string 需被查找的字符串
 * @param c 需要查找的字符
 * @return int 出现的次数
 * @author zhouwei 2013-7-24
 */
int countChar(const char *string,char c);

/**
 * @TODO 根据类型获取年月日十分秒
 * @param int 需要获取的时间类型
 * @return int
 * @author zhouwei 2013-8-15
 */
int getDateByType(int type);

/**
 * @TODO 获取当前时间的yyyy-mm-dd HH:mm:ss
 * @return 时间串，需要在外面释放内存
 * @author zhouwei 2013-8-15
 */
char *getDatetime();

/**
 * @TODO 获取当前时间的yyyy-mm-dd HH:mm:ss
 * @return 时间串，需要在外面释放内存
 * @author zhouwei 2013-8-15
 */
char *getDate();
#endif
