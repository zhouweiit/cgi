#include <stdio.h>
#include <string.h>

#ifndef __http_response_h
#define __http_response_h
#endif

#ifndef _cgi_debug_
#include <fcgi_stdio.h>
#endif

char *htmlDOCTYPE = "<!DOCTYPE html>";

char *htmlMeta = "<meta content=\"text/html; charset=utf-8\" http-equiv=\"Content-Type\">";

char *title = "<title>学生选课系统</title>";

char *head;

char *body;

extern void htmlPrint();
