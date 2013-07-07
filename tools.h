#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __tools_h
#define __tools_h
#endif

typedef union{
    int *pint;
    int **ppint;
    long *plong;
    long **pplong;
    float *pfloat;
    float **ppfloat;
    double *pdouble;
    double **ppdouble;
    char *pchar;
    char **ppchar;
} punion;

typedef struct{
    int length;
    int offset;
    punion point;
} pstruct;

extern char *strupr(char *str);
extern char *urldecode(char *p);
extern char **explode(char *string,char explode);
