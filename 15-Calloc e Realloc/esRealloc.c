// In C, la funzione realloc (reallocation) viene utilizzata per
// ridimensionare un blocco di memoria precedentemente allocato con
// malloc, calloc o un'altra realloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr;
  int n = 5;

  // Alloca memoria per un array di 5 interi
  arr = (int *)malloc(n * sizeof(int));

  if (arr == NULL)
  {
    printf("Allocazione memoria fallita!\n");
    return 1;
  }

  // Inizializza l'array con alcuni valori
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }

  // Mostra l'array originale
  printf("Array originale:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Ridimensiona l'array a 10 elementi
  n = 10;
  arr = (int *)realloc(arr, n * sizeof(int));

  if (arr == NULL)
  {
    printf("Riallocazione memoria fallita!\n");
    return 1;
  }

  // Inizializza i nuovi elementi
  for (int i = 5; i < n; i++)
  {
    arr[i] = i + 1;
  }

  // Mostra il nuovo array
  printf("Array riallocato:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Libera la memoria
  free(arr);

  return 0;
}

// -Se realloc non riesce a trovare memoria sufficiente per ridimensionare, restituisce NULL, ma la memoria originale rimane intatta (non viene liberata).
// -Se si riduce la dimensione della memoria, i dati fuori dal nuovo limite potrebbero essere persi.
// -Se realloc sposta il blocco di memoria, i dati originali vengono copiati nella nuova area.