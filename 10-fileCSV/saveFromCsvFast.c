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
  // Person *person = (Person *)malloc(rowNumber * sizeof(Person));
  Person person[rowNumber];

  int count = 0;
  char buffer[MAX_LINE_LENGTH];
  fgets(buffer, MAX_LINE_LENGTH, file); // Salta l'intestazione

  // Ciclo per oni riga
  while (fgets(buffer, MAX_LINE_LENGTH, file) && count < rowNumber)
  {

    // bufferRead(person, buffer, count);  // Lettura veloce con sscanf

    // Creiamo un array di puntatori ai campi della struct
    char *fields[4];
    int fieldCount = 0;
    // Estrae ogni campo usando strtok e lo memorizza nell'array fields
    char *token = strtok(buffer, ",");
    while (token != NULL && fieldCount < 4)
    {
      fields[fieldCount] = token;
      fieldCount++;
      token = strtok(NULL, ",");
    }
    // Copio le stringhe salvate in field dentro Person
    strcpy(person[count].nome, fields[0]);
    strcpy(person[count].cognome, fields[1]);
    person[count].eta = atoi(fields[2]);
    strcpy(person[count].email, fieldCount > 3 ? fields[3] : "N/A");

    count++;
  }

  for (size_t i = 0; i < count; i++)
  {
    printf("Nome: %s - Cognome: %s - Età: %d - Email: %s",
           person[i].nome,
           person[i].cognome,
           person[i].eta,
           person[i].email);
  }

  // Libero la memoria allocata e chiudo il file
  // free(person);
  fclose(file);
}

int rowCount(FILE *file)
{
  int rowCount = 0;
  char character;
  while ((character = fgetc(file)) != EOF)
    if (character == '\n')
      rowCount++;
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
