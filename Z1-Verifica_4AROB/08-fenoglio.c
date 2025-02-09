
/*
Scrivi un programma in C che permetta di gestire dinamicamente una biblioteca di libri. Ogni libro è rappresentato da una struttura contenente il titolo, l'autore e il numero di copie disponibili. Il programma deve permettere all'utente di aggiungere, modificare e ordinare i libri. L’inventario viene preso da un file CSV.
Struttura:
Definisci una struct chiamata Libro con i seguenti campi:
char titolo[100]: Il titolo del libro.
char autore[100]: L'autore del libro.
int copie: Il numero di copie disponibili.
Input dinamico:
Leggi il file Libri.csv.
Usa calloc per allocare dinamicamente un array di strutture Libro di dimensione uguale al numero di libri presenti.
Inserisci i dati leggendo il file.
Funzionalità:
Il programma deve offrire le seguenti operazioni tramite un menu:
Aggiungi libri:
Permetti all'utente di aggiungere nuovi libri espandendo dinamicamente l'inventario.
Non è richiesto l’input per scegliere i dati del nuovo libro.
Visualizza biblioteca:
Mostra tutti i libri inseriti, con titolo, autore e numero di copie.
Modifica libro:
Cerca un libro per titolo e, se esiste, permette di modificarne il numero di copie.
Ordina biblioteca:
Ordina l’array in base al numero di copie disponibili, in ordine crescente o decrescente.
Richieste aggiuntive
Gestisci correttamente la memoria
Commenta il codice
Usa le funzioni

Comandi utili:
(sono solo un esempio di aiuto)
rewind(file); // Ripristina il puntatore del file all'inizio

fscanf(file,%49[^\n]",variabile) // Leggere 50 caratteri o fino ad \n
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LUNG 100
typedef struct Libro{
    char titolo[LUNG];
    char autore[LUNG];
    int copie;
}Libro;

int contaRighe(FILE *fp){
    int nRighe = 0;
    char buffer[1024];
    fgets(buffer, 1024, fp);
    while(fgets(buffer, 1024, fp)){
        nRighe++;
    }
    rewind(fp);
    return nRighe;
}

void caricaStruct(Libro *p, int nRighe, FILE *fp){
    char buffer[1024];
    fgets(buffer, 1024, fp);
    Libro *pp = p;
    while(fgets(buffer, 1024, fp) && pp < p+nRighe){
        char* token = strtok(buffer, ",");
        strcpy(pp->titolo, token);
        token = strtok(NULL, ",");
        strcpy(pp->autore, token);
        token = strtok(NULL, ",");
        pp->copie = atoi(token); //funzione che converte in intero token
        pp++;
    }
}

void caricaDati(Libro* p, int nAdd, int nRighe){
    Libro *pp;
    for( pp = p+nRighe; pp < p+(nRighe+nAdd); pp++){
        printf("inserisci il titolo del libro: ");
        fflush(stdin);
        scanf("%s", pp->titolo);
        printf("inserisci l'autore del libro: ");
        fflush(stdin);
        scanf("%s", pp->autore);
        printf("inserisci il numero di copie del libro: ");
        scanf("%d", &pp->copie);
        pp++;
    }
}
void visualizzaBiblioteca(Libro *p, int nRighe){
    for (Libro *pp = p; pp < p+nRighe; pp++){
        printf("%s, %s, %d \n", pp->titolo, pp->autore, pp->copie);
    }
}
void modificaLibro(Libro* p, char titolo[LUNG], int nRighe){
    Libro *pp=p;
    bool tro = false;
    while(pp< p+nRighe && !tro){
        if(strcmp(pp->titolo, titolo) == 0){
            tro = true;
            printf("libro trovato");
            int nCopie;
            printf("inserisci il nuovo numero di copie: ");
            scanf("%d", &pp->copie);
            
        }else{
            pp++;
        }
    }
}
void scambioStringhe(char *x, char *y){
    char temp[LUNG];
    strcpy(temp, x);
    strcpy(y, x);
    strcpy(y, temp);
}
void scambioInt(int*x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void ordinaStruct(Libro *p, int nRighe){
    int sup;
    for(sup = nRighe-1; sup>0; sup--){
        for(Libro *pp; pp < p+sup; pp++){
            if(pp->copie > (pp+1)->copie){
                scambioStringhe(pp->autore, (pp+1)->autore);
                scambioStringhe(pp->titolo, (p+1)->titolo);
                scambioInt(&(pp->copie), &((pp+1)->copie));
            }
        }
    }
}
int main(){
    FILE *fp;
    bool esci = false;
    fp = fopen("Libri.csv", "r");
    if(!fp){
        perror("file non aperto");
        return -1;
    }
    
    int nRighe = contaRighe(fp);
    printf("il numero di righe è %d", nRighe);
    Libro *p = (Libro* )calloc(nRighe, sizeof(Libro));
    caricaStruct(p, nRighe, fp);
    if(!p){
        perror("errore nell'allocazione della malloc");
        exit(EXIT_FAILURE);
    }
    do{
        printf("inserisci un numero: \n");
        printf("[0]esci\n");
        printf("[1]Aggiungi libri\n");
        printf("[2]Visualizza biblioteca\n");
        printf("[3]Modifica libro\n");
        printf("[4]Ordina biblioteca\n");
        printf("Scelta: ");
        int scelta;
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 0:
            esci = true;
            break;
        case 1: 
            printf("inserisci il numero di libri che vuoi aggiungere: ");
            int nAdd;
            scanf("%d", &nAdd); //chiedo all'utente quanti libri vuole aggiungere
            p = (Libro*)realloc(p, (nRighe+nAdd)*sizeof(Libro));
            caricaDati(p, nAdd, nRighe);//carico i dati aggiuntivi
            nRighe = nRighe+nAdd;
            break;
        case 2:
            visualizzaBiblioteca(p, nRighe);//visualizza la struct
            break;
        case 3:
            printf("inserisci il titolo di un libro: ");
            fflush(stdin);
            char titolo[LUNG];
            scanf("%s", titolo);
            modificaLibro(p, titolo, nRighe); //modifica il libro
            break;
        case 4:
            ordinaStruct(p, nRighe);//ordina la struttura 
            break;
        }
    }while(!esci);
    fclose(fp);
    free(p);
    p = NULL;
    return 0;
}
