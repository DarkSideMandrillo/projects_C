// In C, la funzione calloc (contiguous allocation) viene utilizzata per
// allocare dinamicamente memoria per un array di elementi, inizializzando
// ogni byte della memoria allocata a zero.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr;
  int n = 5;

  // Alloca memoria per un array di 5 interi, inizializzati a 0
  arr = (int *)calloc(n, sizeof(int));

  if (arr == NULL)
  {
    printf("Allocazione memoria fallita!\n");
    return 1;
  }

  // Stampa gli elementi dell'array, tutti inizializzati a 0
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  // Libera la memoria
  free(arr);

  return 0;
}