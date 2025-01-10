#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arrayLenght =0;
  printf("Questo proramma crea un Array di lunghezza variabile e lo popola proressivamente di int da 1 a N\n");
  printf("Inserisci la lunghezza dell'array: ");
  scanf("%d", &arrayLenght); 

  int *arrayInt = (int *)malloc(arrayLenght * sizeof(int));

  if (!arrayInt)
  {
    perror("allocation failed"); // Stampa un messaggio di errore
    exit(EXIT_FAILURE);          // Termina il programma con stato di errore
  }

  int *p=arrayInt;
  int count=1;
  for (p; p < arrayLenght+arrayInt; p++)
  {
    *p = count;
    count++;
  }

  p=arrayInt;
  for (p; p < arrayLenght+arrayInt; p++)
  {
    printf("%d-", *p);
  }

  free(arrayInt);
  arrayInt=NULL;
}