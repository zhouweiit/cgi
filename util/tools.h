#include <stdio.h>
#include <stdlib.h>
#include <fcgi_stdio.h>
#include <string.h>

#ifndef __tools_h
#define __tools_h
#endif

typedef union punion_{
    void *p;
    void **pp;
    void ***ppp;
} punion;

typedef struct pstruct_{
    int length;
    int offset;
    punion point;
    struct pstruct *pst;
} pstruct;

extern char *strupr(char *str);
extern char *urldecode(char *p);
extern pstruct explode(char *string,char explode);
