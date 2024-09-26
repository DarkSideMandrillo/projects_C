// Occelli Lorenzo
// 75% corretto

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LUNG 100 // Macro
#define DIM 100

//Fare struttura pearson abbiamo nome, cognome, Età e email
typedef struct
{
    char nome[LUNG];
    char cognome[LUNG];
    int eta;
    char email[LUNG];
}Pearson;


int main()
{
    //Dichiaro struttura
    Pearson pers[DIM];
    int i=0;
    //fopen restituisce NULL in caso di problemi
    FILE *file;
    file=fopen("file.csv","r");
    if (file==NULL)
    {
        perror("ERRORE nell'apertura del file");
        return -1;
    }
        
        //GETC legge carattere GETS una stringa
        char buffer[100];//VETTORE
        fgets(buffer, 100, file);
        while (fgets(buffer, 100, file))//Come scrivere fgets(buffer, 100, file)!= NULL
        {
            char *token = strtok(buffer, ",");//(Suddividere il file usare strtok)crea un variabile, *strtok puntatore per leggere primo carattere
            strcpy(pers[i].nome,token);

            token=strtok(NULL, ",");
            strcpy(pers[i].cognome,token);

            token=strtok(NULL, ",");
            pers[i].eta=atoi(token);

            token=strtok(NULL, ",");
            strcpy(pers[i].email,token);
            
            
        
         }
    fclose(file);
    // FOR
    printf("Nome: %s, Cognome: %s, Eta': %i, Email: %s\n", pers[i].nome, pers[i].cognome, pers[i].eta, pers[i].email);

    return 0;
}