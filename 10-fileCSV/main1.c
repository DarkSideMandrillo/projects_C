#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // macro

int main()
{
  // Apri il file CSV in modalità lettura
  FILE *file = fopen("file.csv", "r");
  if (file == NULL)
  {
    perror("Errore nell'apertura del file");
    return 1;
  }

  char buffer[MAX_LINE_LENGTH];

  // Leggi ogni riga del file CSV
  while (fgets(buffer, MAX_LINE_LENGTH, file))
  {
    char *token = strtok(buffer, ",");

    // Stampa ogni valore separato da virgole
    while (token != NULL)
    {
      printf("%s ", token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  // Chiudi il file
  fclose(file);
  return 0;
}