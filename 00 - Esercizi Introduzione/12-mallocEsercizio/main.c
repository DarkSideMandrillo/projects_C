#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arrayLenght;
  printf("Questo proramma crea un Array di lunghezza variabile e lo popola proressivamente di int da 1 a N\n");
  printf("Inserisci la lunghezza dell'array: ");
  scanf("%d", &arrayLenght);

  int *arrayInt = (int *)malloc(arrayLenght * sizeof(int));

  if (!arrayInt)
  {
    perror("allocation failed"); // Stampa un messaggio di errore
    exit(EXIT_FAILURE);          // Termina il programma con stato di errore
  }

  for (size_t i = 0; i < arrayLenght; i++)
  {
    arrayInt[i] = i + 1;
  }

  for (size_t i = 0; i < arrayLenght; i++)
  {
    printf("%d-", arrayInt[i]);
  }
}