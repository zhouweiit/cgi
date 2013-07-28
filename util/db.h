#include "../basic.h"

#ifndef __util_db_h
#define __util_db_h
#include "../util/dlist.h"

typedef struct dbinfo_{
    char **key;
    char **value;
    int length; 
} dbinfo;

#endif
