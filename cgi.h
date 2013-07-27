#include <stdio.h>
#include <sqlite3.h>
#include <fcgi_stdio.h>

#ifndef __cgi_h
#define __cgi_h

#include "http/http.h"
#include "http/response.h"
#include "http/route.h"


#define _free(point) free(point); point = NULL;
#endif
