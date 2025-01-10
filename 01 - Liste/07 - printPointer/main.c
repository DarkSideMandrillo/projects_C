
#include <stdio.h>
#include <stdlib.h>

void FUNC(int *pippo)
{
    printf("FUNC contenuto di pippo: %p\n", pippo);
    printf("FUNC dereferenziazione di pippo:%d\n", *pippo);
    printf("FUNC indirizzo di pippo:%p\n", &pippo);
    printf("-\n");
    *pippo=50;
}

int main()
{
    int a = 1;
    int b = 10;
    int *p = &a;

    printf("contenuto di a: %d\n", a);
    printf("indirizzo di a: %p\n", &a);
    printf("-\n");
    printf("contenuto di p: %p\n", p);
    printf("dereferenziazione di p:%d\n", *p);
    printf("indirizzo di p:%p\n", &p);
    printf("-\n");
    FUNC(p);
    printf("contenuto di a: %d\n", a);
    printf("indirizzo di a: %p\n", &a);
    printf("-\n");
    printf("-\n");
    printf("contenuto di p: %p\n", p);
    printf("dereferenziazione di p:%d\n", *p);
    printf("indirizzo di p:%p\n", &p);



    return 0;

}