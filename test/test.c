#include <stdio.h>
#include <stdlib.h>

int test(int *a){
    
}

int main(int argc,char **argv){
    char *a= "123123";
    char **b = &a;
    void *c = (void *)b;
    printf("%s",*(char **)c);
}
