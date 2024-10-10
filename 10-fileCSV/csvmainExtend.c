#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int eta;
    char mail[40];
} Persona;


int main()
{
char buffer[1024];
FILE *fp = fopen("file.csv","r");

if (fp == NULL)
{
    perror("File non aperto");
    return 1;
}

Persona persone[10];
int count =0;

while (fgets(buffer,1024,fp))
{
    char *token = strtok(buffer,",");
    while (token!=NULL)
    {
        printf("-%s",token);
        token = strtok(NULL,",");
        strcpy(persone[count].nome,token);
    }
count++;
}

fclose(fp);

return 0;
}
// 1 - char *token = strtok(buffer,",") strtok("NULL,",")
// 2 - creo struct nome,cognome,eta,mail e faccio un array di struct
// 3 - strcpy(person[count].nome, token);
// Esercizio: Creare una func per determinare il numero di righe del file e creare struct adeguata
