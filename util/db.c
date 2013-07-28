#include "db.h"
static void destroyDBinfo(void *data){
    dbinfo *info = (dbinfo *)data;
    int i = 0;
    for(i; i < info->length; i++){
        free(info->key[i]);
        free(info->value[i]);
    }
    free(info->key);
    free(info->value);
}

static int selectCallback(void *data,int count,char **values,char **names){
    dlist *resultList = (dlist *)data;
    dbinfo *info = (dbinfo *)malloc(sizeof(dbinfo));
    info->key = (char **)malloc(sizeof(char *) * count);
    info->value = (char **)malloc(sizeof(char *) * count);
    int i = 0;
    info->length = count;
    for(i; i < count; i++){
        info->key[i] = (char *)malloc((strlen(names[i])+1)*sizeof(char));
        strcpy(info->key[i],names[i]);

        info->value[i] = (char *)malloc((strlen(values[i])+1)*sizeof(char));
        strcpy(info->value[i],values[i]);
    }
    dlistInsert(resultList,NULL,info);
    return 0;
}

int selectSqlite3(sqlite3 *db,char *sql,dlist **list){
    char *errMsg = NULL;
    *list = (dlist *)malloc(sizeof(dlist));
    dlistInit(*list,NULL,destroyDBinfo,NULL);
    int result = sqlite3_exec(db,sql,selectCallback,*list,&errMsg);    
    sqlite3_free(errMsg);
    if (result == SQLITE_OK){
        return 0;    
    } else {
        return 1;    
    }
}

int insertSqlite3(sqlite3 *db,char *sql,int *lastId){
    char *errMsg = NULL;
    int result = sqlite3_exec(db,sql,NULL,NULL,&errMsg);    
    sqlite3_free(errMsg);
    if (result == SQLITE_OK){
        return 0;    
    } else {
        return 1;    
    }
}

int updateSqlite3(sqlite3 *db,char *sql,int *effectNum){
    char *errMsg = NULL;
    int result = sqlite3_exec(db,sql,NULL,NULL,&errMsg);    
    sqlite3_free(errMsg);
    *effectNum = sqlite3_changes(db);
    if (result == SQLITE_OK){
        return 0;    
    } else {
        return 1;    
    }
}

void destroySqlite3info(dlist *dbinfo){
    dlistDestroy(dbinfo);
    _free(dbinfo);
}

int closeSqlite3(sqlite3 *db){
    return sqlite3_close(db);    
}

sqlite3 *createConnectionSqlite3(char *dbname){
    sqlite3 *db = NULL;
    const char *errMsg = 0;
    int result = 0;
    result = sqlite3_open(dbname,&db);
    if (result){
        sqlite3_close(db);
        errMsg = sqlite3_errmsg(db);
        return NULL;
    } else {
        return db;
    }
}
