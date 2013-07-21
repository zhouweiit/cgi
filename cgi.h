#include <stdio.h>
#include <fcgi_stdio.h>

//#define _cgi_debug_
#ifndef _cgi_debug_
#include <fcgi_stdio.h>
#endif

#ifndef __cgi_h
#define __cgi_h
#endif

#ifndef __http_http_h
#include "http/http.h"
#endif
