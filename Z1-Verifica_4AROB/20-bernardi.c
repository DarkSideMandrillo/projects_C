
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 1024

typedef struct Studenti
{
    int id;
    char nome[20];
    char cognome[20];
    char classe[2];
    int eta;
} Studenti;

int contaRighe(FILE *fp)
{

    char *buffer[LUNG];
    int k = 0; //!! prima riga da togliere dal conteggio
    while(fgets(buffer, LUNG, fp))
    {
        k++;
    }
    rewind(fp);

    return k;
}

void caricaFile(FILE *fp, Studenti *scuola, int n) //!! non la chiami
{
    char *buffer[LUNG]; //!! no pointer
    Studenti *p = scuola;
    int k = 0;
    fgets(buffer, LUNG, fp);
    while (fgets(buffer, LUNG, fp) && k < n)
    {
        char *token = strtok(buffer, ",");
        p->id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(p->nome, token);
        token = strtok(NULL, ",");
        strcpy(p->cognome, token);
        token = strtok(NULL, ",");
        strcpy(p->classe, token);
        token = strtok(NULL, ",");
        p->eta = atoi(token);
        k++;
    }
    rewind(fp);
}
void aggiungiStudente(Studenti *scuola, int n)
{
    Studenti *p = scuola + n; //!! queste sono le cose da commentare. p punta alla fine dell'array
    char nomeT[20];
    char cognomeT[20];
    char classeT[2];
    int etaT;

    printf("inserisci nome: ");
    scanf("%s", nomeT);
    printf("inserisci cognome: ");
    scanf("%s", cognomeT);
    printf("inserisci classe: ");
    scanf("%s", classeT);
    printf("inserisci eta: ");
    scanf("%d", &etaT);

    //assegnamento nuovo studente 
    p->id = n;
    strcpy(p->nome, nomeT);
    strcpy(p->cognome, cognomeT);
    strcpy(p->classe, classeT);
}

void visualizza(Studenti *scuola, int n){
    Studenti *p=scuola;
    for(p;p<n+scuola;p++){
        printf("%d %s %s %s %d",p->id, p->nome,p->cognome,p->classe,p->eta);
    }

}

void eliminaStudenti(Studenti *scuola, int n){
    char classeT[2];
    Studenti *p=scuola;

    printf("inserisci la classe :");
    scanf("%s",classeT);
    //scorro la struttua con puntatore d'appoggio
    for(p;p<n+scuola;p++){
        if(strcmp(p->classe,classeT)==0){
          

        }
    }



}

int main()
{
    FILE *fp;
    fp = fopen("student_list.csv", "r");
    int n = contaRighe(fp);

    Studenti *scuola = (Studenti *)calloc(n, sizeof(Studenti)); //!! avevo richiesto malloc
    int scelta;
    printf("Inserisci 1 se vuoi aggiungere 1 studente :\n");
    printf("Inserisci 2 se vuoi visualizzare la scuola :\n");
    printf("Inserisci 1 se vuoi eliminare  1 classe :\n");
    scanf("%d", &scelta);

    do
    {
        switch (scelta)
        {
        case 1:
        {
            aggiungiStudente(scuola, n);
            n = n + 1;
            scuola = (Studenti *)realloc(n * sizeof(Studenti)); //!! errata. poi bisogna farla prima!
            break;
        }
        case 2:
        {
            visualizza(scuola,n);
            break;

        }
        case 3:
        {
            eliminaStudenti(scuola,n);
            break;
        }
        default:
        {
            perror("scelta non valida !!!");
        }
        }
    } while (scelta >= 1 && scelta <= 3);

    free(scuola);
    
}
