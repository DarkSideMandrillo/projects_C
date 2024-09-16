#include <stdio.h>
#include <string.h> // Necessaria per usare strcpy()

struct Struttura
{
  char carattere;
  char arrayCarattere[5];
  int integer;
};

void funcStampa(struct Struttura *pointerStr);
void funcPopola(struct Struttura *pointerStr);

int main()
{
  struct Struttura str;
  struct Struttura *ptrStr = &str;

  // Popolazione dei dati in str
  str.carattere = 'A';
  str.integer = 15;

  //  strcpy(dest, source)
  //  Commentato altrimenti perde il valore di str.integer
  //  strcpy(str.arrayCarattere, "ciao123"); // Compromette i dati adiacenti. Comportamento indefinito
  //  printf("%s\n", str.arrayCarattere);

  //  snprintf(dest, size, source)
  //  taglia a lunhezza fissa[Controllo buffer overlow]. Ricorda ultimo elemento array è \0
  snprintf(str.arrayCarattere, sizeof(str.arrayCarattere), "ciao123");
  printf("%s\n", str.arrayCarattere);

  //  --------------------- Stampa in Main -------------------------------------- //

  printf("%d\n", str.integer);
  ptrStr->integer = 10;
  printf("%d\n", str.integer);
  printf("%s\n", ptrStr->arrayCarattere);
  printf("%c\n", ptrStr->carattere);

  //  --------------------- Richiamo funcStampa - for printf() -------------------------------------- //

  printf("Pointer ptrStr: %p\n", ptrStr); // stesso risultato di printf(pointerStr)
  printf("Address str%p\n", &str);
  funcStampa(&str);

  //  --------------------- Richiamo funcPopola - for scanf() -------------------------------------- //

  int a = 0;
  scanf("%d", &a);
  printf("%d\n", a);
  funcPopola(&str);

  return 0;
}

//  --------------------- Funzione funcStampa -------------------------------------- //
void funcStampa(struct Struttura *pointerStr)
{
  printf("Pointer pointerStr: %p\n", pointerStr);
  printf("%s\n", pointerStr->arrayCarattere);
  printf("%d\n", pointerStr->integer);
  printf("%c\n", pointerStr->carattere);
}

void funcPopola(struct Struttura *pointerStr) {}