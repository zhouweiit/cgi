#include <stdio.h>
#include <stdlib.h>
#include "../tools.h"

int test(int *a){
    
}

int main(int argc,char **argv){
    char *a = "123"; 
    void *b  = (void *)a;
    printf("%s",(char *)b);
}
