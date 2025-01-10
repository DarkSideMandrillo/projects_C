#include <stdio.h>

int main(){
    int x=4;
    int a =0;
    a = x++ + x;
    printf("%d\n",a);
    printf("%d",x);
}