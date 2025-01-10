
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 1024

typedef struct Studenti{
    int ID;
    char nome[20];
    char cognome[20];
    char classe[2];
    int eta;
}Studenti;

int contarighe(FILE *fp){
    int n=0;
    char buffer[LUNG];
    fgets(buffer, LUNG, fp);
    while(fgets(buffer, LUNG, fp)){
        n++;
    }
    rewind(fp);
    return n;
}

void leggifile(FILE *fp, int n, Studenti *p){
    char buffer[LUNG];
    Studenti *pp = p;
    fgets(buffer, LUNG, fp);
    while(fgets(buffer, LUNG, fp) && pp < p+n){
        char *token = strtok(buffer, ",");

        pp->ID = atoi(token);
        token = strtok(NULL, ",");

        strcpy(pp->nome, token);
        token = strtok(NULL, ",");

        strcpy(pp->cognome, token);
        token = strtok(NULL, ",");

        strcpy(pp->classe, token);
        token = strtok(NULL, ",");

        pp->eta = atoi(token);

        pp++;

    }
}

void visualizza(Studenti *p, int n){
    Studenti *pp=p;
    for(pp; pp < p+n; pp++){
        printf("%d %s %s %s %d\n", pp->ID, pp->nome, pp->cognome, pp->classe, pp->eta);
    }
}

void aggiungi(Studenti *p, int n){
    Studenti *pp = p+n;
    int id;
    char nome[50];
    char cognome[50];
    char classe[50];
    int eta;
    printf("inserisci un id: ");
    scanf("%d", &id);

    printf("inserisci un nome: ");
    scanf("%s", nome);

    printf("inserisci un cognome: ");
    scanf("%s", cognome);

    printf("inserisci una classe: ");
    scanf("%s", classe);

    printf("inserisci un eta: ");
    scanf("%d", &eta);

    pp->ID = id;
    strcpy(pp->nome, nome);
    strcpy(pp->cognome, cognome);
    strcpy(pp->classe, classe);
    pp->eta = eta;

}

void elimina(Studenti *p, int n){
    //fare ricerca scorrendo tutta la struttura creando un file di appoggio pp dopo uso strcmp per paragonare la classe della struttura e quella data in input 
    //se la condizione è vera cancello tutto e devo concatenare la riga cancellata con quella dopo
    //!! e poi riallocare
    Studenti *pp = p; 
    char classe[20];
    printf("inserisci la classe da cancellare: ");
    scanf("%s", classe);
    for(pp; pp < n+p; pp++){
        if(strcmp(pp->classe, classe) == 0){
            pp->ID = 0;
            strcpy(pp->nome, "\0");
            strcpy(pp->cognome, "\0");
            strcpy(pp->classe, "\0");
            pp->eta = 0;
            strcat(pp->classe, "\0");
        
        }
    }
}

int main(){
    char nomeFile[] = "student_list.csv";
    FILE *fp;
    fp = fopen(nomeFile, "r");
    int n = contarighe(fp);
    Studenti *scuola;
    scuola = (Studenti *)calloc(n, sizeof(Studenti));
    leggifile(fp, n, scuola);
    visualizza(scuola, n);
    int scelta;

    do{
        printf("1 per aggiungere, 2 per visualizzare, 3 elimina studente per classe: ");
        scanf("%d", &scelta);
        switch(scelta){

            case 1: //!! n++ da fare prima
                scuola = (Studenti *)realloc(scuola, n+1*sizeof(Studenti)); //!! la matematica!
                aggiungi(scuola, n); //
                n++;
                break;
            case 2:
                visualizza(scuola, n);
                break;
            case 3:
                elimina(scuola, n);
                break;
            
            default:
                printf("errore");
                break;
        }

    }while(scelta >= 1 && scelta <= 3);


}
