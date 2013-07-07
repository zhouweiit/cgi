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
