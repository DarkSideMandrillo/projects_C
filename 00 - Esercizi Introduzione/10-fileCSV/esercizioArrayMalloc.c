#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("- %d\n", arr[i]);
    }
}