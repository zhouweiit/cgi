#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../util/dlist.h"
#include "../util/hash.h"

#ifndef __http_h
#define __http_h
#endif


typedef struct strData_{
    char *key;
    void *data
} strData;
