#include "tools.h"

char *strupr(char *str){
    char *p = str;
    while (*p != '\0'){
        if(*p >= 'a' && *p <= 'z'){
            *p -= 0x20;
        }
        p++;
    }
    return str;
}

char *urldecode(char *p){
    char *pm = p;
    register i = 0;
    while(*(p+i)){
        if ((*p=*(p+i)) == '%'){
            *p=*(p+i+1) >= 'A' ? ((*(p+i+1) & 0XDF) - 'A') + 10 : (*(p+i+1) - '0');
            *p=(*p) * 16;
            *p+=*(p+i+2) >= 'A' ? ((*(p+i+2) & 0XDF) - 'A') + 10 : (*(p+i+2) - '0');
            i+=2;
        } else if (*(p+i)=='+'){
            *p=' ';
        }
        p++;
    }
    *p='\0';
    return pm;
}

pstruct explode(char *string,char explode){
    int strlength = strlen(string);
    int markNum = 0;
    int i = 0;
    for (i = 0;i < strlength;){
        if (string[i++] == explode){
            markNum++;
        }     
    }
    int ereryStrLen[markNum];
    int strlen = 0;
    markNum = 0;
    for (i = 0;i < strlength;){
        strlen++;
        if ((i + 1) == strlength){
            ereryStrLen[markNum++] = strlen;
        }
        if (string[i++] == explode){
            ereryStrLen[markNum++] = strlen - 1;
            strlen = 0;
            continue;
        }
    }
    char **explodeStr = (char **) malloc((markNum) * sizeof(int));
    punion p;
    p.ppchar = explodeStr;
    for (i = 0;i < markNum;i++){
        *explodeStr = (char *) malloc(ereryStrLen[i] + 1);
        char *ppexplodeStr = *explodeStr;
        for (strlen = 0;strlen < ereryStrLen[i];strlen++){
            **explodeStr = *string;
            (*explodeStr)++;
            string++;
        }
        **explodeStr = '\0';
        *explodeStr = ppexplodeStr;
        explodeStr++;
        string++;
    }
    pstruct pStruct = {markNum,1,p}; 
    return pStruct;
}
