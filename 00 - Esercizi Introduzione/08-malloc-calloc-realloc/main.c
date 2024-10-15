#include <stdio.h>
#include <stdlib.h>

void check_allocation(void *ptr);
void arrayIntInit(int *ptr, int dimension);
void arrayIntStamp(int *ptr, int dimension);

int main()
{
  int *arrayInt1 = (int *)malloc(10 * sizeof(int)); // Alloca spazio in memoria per 10 interi
  check_allocation(arrayInt1);

  int *arrayInt2 = (int *)calloc(10, sizeof(int)); // Alloca spazio in memoria per 10 interi e assegna il valore 0 a ognuno
  check_allocation(arrayInt2);

  arrayInt1 = (int *)realloc(arrayInt1, 20 * sizeof(int)); // modifica arrayInt1 allocando spazio in memoria per 20 interi. N.B. allocare non modifica il valore al quale punta il puntatore

  arrayIntInit(arrayInt1, 20);
  arrayIntInit(arrayInt2, 10);

  // Stampa l'indirizzo di memoria dell'array 1
  printf("Indirizzo di memoria dell'array: %p\n", (void *)arrayInt1); // N.B. Sto stampando l'indirizzo al quale punta arrayInt1 e non l'indirizzo della variabile arrayInt1
  arrayIntStamp(arrayInt1, 20);
  // Stampa l'indirizzo di memoria dell'array 2
  printf("Indirizzo di memoria dell'array: %p\n", (void *)arrayInt2);
  arrayIntStamp(arrayInt2, 10);

  free(arrayInt1);
  free(arrayInt2);
  return 0;
}

// Gestisci l'errore di allocazione
void check_allocation(void *ptr)
{
  if (!ptr)
  {
    perror("allocation failed"); // Stampa un messaggio di errore
    exit(EXIT_FAILURE);          // Termina il programma con stato di errore
  }
}

void arrayIntInit(int *ptr, int dimension)
{
  for (size_t i = 0; i < dimension; i++)
    ptr[i] = i + 1;
}

void arrayIntStamp(int *ptr, int dimension)
{
  // Stampa l'indirizzo di memoria dell'array
  printf("Indirizzo di memoria dell'array: %p\n", (void *)ptr);
  {
    for (size_t i = 0; i < dimension; i++)
      printf("%d\n", ptr[i]);
  }
}