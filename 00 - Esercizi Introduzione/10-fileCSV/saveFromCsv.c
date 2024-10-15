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

int rowCount(FILE *file);
void bufferRead(Person *person, char buffer[MAX_LINE_LENGTH], int count);

int main()
{
  // Apri il file CSV in modalità lettura
  FILE *file = fopen("file.csv", "r");
  if (file == NULL)
  {
    perror("Errore nell'apertura del file");
    fclose(file);
    return -1;
  }
  int rowNumber = rowCount(file);
  Person *person = (Person *)malloc(rowNumber * sizeof(Person));

  int count = 0;
  char buffer[MAX_LINE_LENGTH];
  fgets(buffer, MAX_LINE_LENGTH, file); // Salta l'intestazione

  // Ciclo per oni riga
  while (fgets(buffer, MAX_LINE_LENGTH, file) && count < rowNumber)
  {

    // bufferRead(person, buffer, count);  // Lettura veloce con sscanf

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
    else
    {
      // Se non c'è email, metto un valore predefinito
      strcpy(person[count].email, "N/A\n");
      token = strtok(NULL, ",");
    }
    count++;
  }

  for (size_t i = 0; i < count; i++)
  {
    printf("Nome: %s - Cognome: %s - Età: %d - Email: %s", person[i].nome, person[i].cognome, person[i].eta, person[i].email);
  }

  // Libero la memoria allocata e chiudo il file
  free(person);
  fclose(file);
}

int rowCount(FILE *file)
{
  int rowCount = 0;
  rewind(file);
  char buffer[1024];
  // char character;
  // while ((character = fgetc(file)) != EOF)
  //   if (character == '\n')
  //     rowCount++;
  // rewind(file);
  // return rowCount;
  while (fgets(buffer, MAX_LINE_LENGTH, file)!=NULL)
  {
    rowCount++;
  }
  rewind(file);
  return rowCount;
   
}

// Funzione per legere i dati con sscanf

void bufferRead(Person *person, char buffer[MAX_LINE_LENGTH], int count)
{
  int num_fields = sscanf(buffer, "%19[^,],%19[^,],%d,%29[^,]",
                          person[count].nome,
                          person[count].cognome,
                          &person[count].eta,
                          person[count].email);
}
