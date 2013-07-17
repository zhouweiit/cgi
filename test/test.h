#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __test_h
#define __test_h
#endif

#ifndef __dlist_h
#include "../util/dlist.h"
#endif

#ifndef __hash_h
#include "../util/hash.h"
#endif

typedef struct charValue_{
    char *key;
    void *data;
} charValue;

