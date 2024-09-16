#include <stdio.h>

struct prova
{
  int x;
  char y[5];
};

int main()
{
  struct prova str;

  int a = 0;
  char b;
  char c[3] = {0}; // Inizializza tutto l'array a 0

  // Scanf()
  scanf("%d", &a);  // Passa l'indirizzo di 'a'
  scanf(" %c", &b); // Passa l'indirizzo di 'b', con spazio prima di '%c' per ignorare spazi bianchi. IMPORTANTE, usare uno spazio " %c"
  // scanf("%s", c);   // Problema buffer overflow. Non serve passare l'indirizzo, perchè c è l'indirizzo di inizio array
  scanf("%2s", c); // Risolve problema buffer overflow accettando solo 2 caratteri dal buffer di inserimento
  while (getchar() != '\n')
    ; // Pulisce il buffer di input
  scanf("%d", &str.x);
  scanf("%4s", str.y);

  // Stampa i valori inseriti
  printf("a = %d\n", a);
  printf("b = %c\n", b);
  printf("c = %s\n", c);

  printf("str.x = %d\n", str.x);
  printf("str.y = %s\n", str.y);

  return 0;
}