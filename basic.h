#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <fcgi_stdio.h>
#include <sqlite3.h>

#define _free(point) free(point); point = NULL;
#define _memset(point) memset(point,0,sizeof(point));point = NULL;
