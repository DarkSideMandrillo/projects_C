#include <stdio.h>
#include <stdlib.h> // usata per atoi
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct
{
  char nome[20];
  char cognome[20];
  int eta;
  char email[30];
} Person;

int main()
{
  // Apri il file CSV in modalità lettura
  FILE *file = fopen("file.csv", "r");
  if (file == NULL)
  {
    perror("Errore nell'apertura del file");
  }

  Person person[100];
  int count = 0;

  char buffer[MAX_LINE_LENGTH];

  fgets(buffer, MAX_LINE_LENGTH, file); // Salta l'intestazione

  // Ciclo per oni riga
  while (fgets(buffer, MAX_LINE_LENGTH, file) && count < 100)
  {
    char *token = strtok(buffer, ",");
    // Inserisco nome
    if (token != NULL)
    {
      strcpy(person[count].nome, token);
      token = strtok(NULL, ",");
    }
    // Inserisco cognome
    if (token != NULL)
    {
      strcpy(person[count].cognome, token);
      token = strtok(NULL, ",");
    }
    // Inserisco età
    if (token != NULL)
    {
      person[count].eta = atoi(token);
      token = strtok(NULL, ",");
    }
    // Inserisco email
    if (token != NULL)
    {
      strcpy(person[count].email, token);
      token = strtok(NULL, ",");
    }
    count++;
  }

  for (size_t i = 0; i < count; i++)
  {
    printf("Nome: %s - Cognome: %s - Età: %d - Email: %s", person[i].nome, person[i].cognome, person[i].eta, person[i].email);
  }
}