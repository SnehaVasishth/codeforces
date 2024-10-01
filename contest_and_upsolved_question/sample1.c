#include <stdio.h>

int main(){

    // char p[]= "%d\r\n";
    // p[1]='c';
    // printf(p,120);
    // printf("%d",sizeof(p));

    int a[20];
    int i=20;
    a[i--]=i;
    printf("%d\n", a[20]);
    printf("%d,%d,%d", a[0],i,a[++i]);
}
