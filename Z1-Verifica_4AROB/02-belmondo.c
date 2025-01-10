
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 100

typedef struct Libro{
    char titolo[LUNG];
    char autore [LUNG];
    int copie;
}Libro;

int trovaRighe(FILE *fp){
    int nRighe = 0;
    char buffer[1024];
    fgets(buffer, 1024, fp);
    while(fgets(buffer, 1024, fp)!=NULL){
        nRighe++;
    }
    //printf("%d", nRighe);
    return nRighe;
}

void caricaStruct(FILE *fp, Libro *p, int nRighe){
    char buffer[1024];
    Libro *pp = p;
    fgets(buffer, 1024, fp); // per tigliere la prima riga
    while(fgets(buffer, 1024, fp)&& pp < p + nRighe){
        char *token = strtok(buffer, ",");
        strcpy(pp->titolo, token);
        token = strtok(NULL, ",");
        strcpy(pp->autore, token);
        token = strtok(NULL, ",");
        pp->copie = atoi(token);
        pp++;
    }
}

void visualizzaBiblioteca(Libro *p, int nRighe){
    Libro *pp;
    for(pp = p; pp < p + nRighe; pp++){
        printf("%s %s %d", pp->titolo, pp->autore, pp->copie);
    }
}

/*void aggiungiLibri(Libro *p, int nRighe, int addLibri){
    int cont = nRighe + 1;
    Libro *pp = p + nRighe;
    for(pp = p + nRighe; pp< p + nRighe.addLi)
    pp->autore = "CIAO";
    pp->titolo = "CIAO";

}*/

int main(){
    char nomeFile [1024]= "Libri.csv";

    FILE *fp = fopen(nomeFile, "r");

    if(fp == NULL){
        perror("Errore nell'apertura del FILE!");
    }
    int nRighe = trovaRighe(fp);

    Libro *biblioteca = (Libro *)calloc(nRighe, sizeof(Libro)); 
    if(biblioteca == NULL){
        printf("Errore nell'allocazione di memoria.");
    } 
    rewind(fp);
    caricaStruct(fp, biblioteca, nRighe); //!! manca rewind
    fclose(fp);
    bool ok = false;
    int scelta;
    int addLibri;    

    do{
        printf("Inserisci la scelta:\n1)Aggiungi libri\n2)Visualizza biblioteca\n3)Modifica libro\n4)Ordina biblioteca\n");
        scanf("%d", &scelta);

        switch(scelta) //!! manca {} e niente :
        {
            case 1:
                
                printf("Inserisci il numero di libri che vuoi aggiungere: ");
                scanf("%d", &addLibri);
                //!! nRighe+=addLibri
                //Libro *biblioteca = (Libro *)realloc(biblioteca, nRighe + addLibri * sizeof(Libro)); //!! matematica. Da problemi anche nesso witch case
                //aggiungiLibri(biblioteca, nRighe, addLibri);
                break;
            case 2:
                visualizzaBiblioteca(biblioteca, nRighe);                
                break;
            case 3:
                // modificaLibro();
                break;
            case 4:
                // ordinaBiblioteca();
                break;
        }
    }while(!ok);
    

    free(biblioteca);
    biblioteca = NULL;
    return 0;
}
