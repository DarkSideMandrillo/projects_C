#include <stdio.h>

int main()
{
  int a, b, c;

  // Puntatori per le variabili a, b e c
  int *ptrA = &a;
  int *ptrB = &b;
  int *ptrC = &c;

  // Assegna il valore 10 a 'a' tramite il puntatore
  *ptrA = 10;

  // Assegna il valore 20 a 'b' tramite il puntatore
  *ptrB = 20;

  // Somma di 'a' e 'b', il risultato viene memorizzato in 'c' tramite il puntatore
  *ptrC = *ptrA + *ptrB;

  // Stampa i valori di 'a', 'b' e 'c' usando i puntatori
  printf("Valore di a: %d\n", *ptrA);
  printf("Valore di b: %d\n", *ptrB);
  printf("Valore di c (somma di a e b): %d\n", *ptrC);

  // Modifica il valore di 'a' tramite il puntatore
  *ptrA = 15;

  // Incrementa il valore di 'b' di 5 tramite il puntatore
  *ptrB += 5;

  // Stampa i nuovi valori di 'a' e 'b' usando i puntatori
  printf("Nuovo valore di a: %d\n", *ptrA);
  printf("Nuovo valore di b: %d\n", *ptrB);

  return 0;
}