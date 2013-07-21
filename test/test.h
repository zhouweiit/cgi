#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __test_test_h
#define __test_test_h
#endif

#ifndef __http_request_h
#include "../http/request.h"
#endif

#ifndef __util_dlist_h
#include "../util/dlist.h"
#endif

#ifndef __util_hash_h
#include "../util/hash.h"
#endif

#ifndef __util_tools_h
#include "../util/tools.h"
#endif

typedef struct charValue_{
    char *key;
    void *data;
} charValue;

