#include <stdio.h>
#include <stdlib.h>
#include <fcgi_stdio.h>
#include <string.h>

#ifndef __tools_h
#define __tools_h
#endif

#define GC(P) free(p);p = NULL;

typedef union punion{
    char *pchar;
    char **ppchar;
    int *pint;
    int **ppint;
    long *plong;
    long **pplong;
    float *pfloat;
    float **pploat;
    double *pdouble;
    double **ppdouble;
} punion;

typedef struct pstruct{
    int length;
    int offset;
    punion point;
    struct pstruct *pst;
} pstruct;

extern char *strupr(char *str);
extern char *urldecode(char *p);
extern pstruct explode(char *string,char explode);
extern void GCPstruct(pstruct pst);
