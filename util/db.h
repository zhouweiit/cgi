#include "../basic.h"

#ifndef __util_db_h
#define __util_db_h
#include "../util/dlist.h"

typedef struct dbinfo_{
    char **key;
    char **value;
    int length; 
} dbinfo;

/**
 * @TODO 查询信息
 * @param db 数据库
 * @param sql sql语句
 * @param list dlist的指针的指针
 * @return 0成功1失败
 * @author zhouwei 2013-7-28
 */
int selectSqlite3(sqlite3 *db,char *sql,dlist **list);

/**
 * @TODO 插入一条数据
 * @param db
 * @param sql
 * @return 0成功1失败
 * @author zhouwei 2013-7-28
 */
int insertSqlite3(sqlite3 *db,char *sql);

/** 
 * @TODO 更新一条数据
 * @param db
 * @param sql
 * @param effectNum 影响的行数
 * @return 0成功1失败
 * @author zhouwei 2013-7-28
 */
int updateSqlite3(sqlite3 *db,char *sql,int *effectNum);

/**
 * @TODO 销毁查询返回的list
 * @param dbinfo
 * @return void
 * @author zhouwei 2013-7-28
 */
void destroySqlite3info(dlist *dbinfo);

/**
 * @TODO 关闭数据链接
 * @param db
 * @return 0成功1失败
 * @author zhouwei 2013-7-28
 */
int closeSqlite3(sqlite3 *db);

/**
 * @TODO 建立链接
 * @param dbname 数据库名称
 * @return sqlite3或者NULL
 * @author zhouwei 2013-7-28
 */
sqlite3 *createConnectionSqlite3(char *dbname);
#endif
