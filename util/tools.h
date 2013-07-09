#include <stdio.h>
#include <stdlib.h>
#include <fcgi_stdio.h>
#include <string.h>

#ifndef __tools_h
#define __tools_h
#endif

typedef struct pstruct_{
    int length;
    int offset;
    void *data;
    struct pstruct *pst;
    void (*destroy)(void *);
} pstruct;

extern char *strupr(char *str);
extern char *urldecode(char *p);
extern pstruct explode(char *string,char explode);
