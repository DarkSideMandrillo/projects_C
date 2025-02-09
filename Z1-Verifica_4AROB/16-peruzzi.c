
/*
Scrivi un programma in C che permetta di gestire dinamicamente una biblioteca di libri. 
Ogni libro è rappresentato da una struttura contenente il titolo, 
l'autore e il numero di copie disponibili. 
Il programma deve permettere all'utente di aggiungere, modificare e ordinare i libri. 
L’inventario viene preso da un file CSV.
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
per la calloc inv = (inventario *)(n, inventario)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Libri
{
    char titolo[100];
    char autore[100];
    int copie;
}Libri;

int leggiFile(char nomeFile[]){

    FILE *fp;

    fp = fopen(nomeFile, "r");

    int n = 0;
    char titolo[100];
    char autore[100];
    int copie = 0;

    if(!fp){
        perror("errore");
    }else{
        while(fscanf(fp, "%s,%s,%d", titolo, autore, &copie) != EOF){ //!! così non funziona
            n++;
        }
    }

    fclose(fp);
    return n - 1;

}

void caricaStruct(Libri *libri, char nomeFile[]){

    
    FILE *fp;

    fp = fopen(nomeFile, "r");

    int n = 0;
    char titolo[100];
    char autore[100];
    int copie = 0;

    if(!fp){
        perror("errore");
    }else{
        while(fscanf(fp, "%s,%s,%d", titolo, autore, &copie) != EOF){
            
            strcpy(libri->titolo, titolo);
            strcpy(libri->autore, autore);
            libri->copie = copie;

            printf("%s", libri->autore);
            n++;
        }
    }

    fclose(fp);
    
}

void aggiungiLibri(Libri *l, int nRighe){

    /*
    Permetti all'utente di aggiungere nuovi libri espandendo dinamicamente l'inventario.
    Non è richiesto l’input per scegliere i dati del nuovo libro.
    */

   int n = 0;

   Libri *a = l;

   do{
        printf("Quanti libri vuoi aggiungere?\n");
        scanf("%d", &n);

   }while(n < 0);

    a = (Libri *)realloc(l, n); //reallocazione di memoria !! Errata

}

void stampaBiblioteca(Libri *libri, int nRighe){
    //Mostra tutti i libri inseriti, con titolo, autore e numero di copie.

    for(int k = 0; k < nRighe; k++){

        printf("Nome: ", libri->titolo);
        printf("Autore: ", libri->autore);
        printf("Numero di copie: ", libri->copie);

    }
    
}

void modificaLibro(Libri *libri, int nRighe){

    //Cerca un libro per titolo e, se esiste, permette di modificarne il numero di copie.

    bool tro = false;
    char nome[100];
    int nCopie = 0;
    int k = 1; //parto da 1 perchè non leggo la prima riga

    while(tro && k <= nRighe){
        printf("inserisci il libro che vuoi cercare:\n");
        scanf("%s", nome);
        if(strcmp(libri->titolo, nome) == 0){//errata libri[k]
            printf("inserisci il numero di copie: ");
            scanf("%d", &nCopie);

            libri[k].copie = nCopie; 
            
            tro = true;

        }

        k++;
    }
}
int main(){

    char nomeFile[] = "Libri.csv";

    int nRighe = leggiFile(nomeFile);


    Libri *libri = (Libri *)calloc(nRighe, nRighe); //alloca la memoria

    caricaStruct(&libri, nomeFile);

    int menu = 0;
    printf("inserire l'opzione necessaria: \n 1.Aggiungi libri: \n2.Visualizza biblioteca: \n3.Modifica libro: \n4.Ordina biblioteca:\n");
    scanf("%d", &menu);

    switch(menu){
        case 1:
            aggiungiLibri(&libri, nRighe);
        break;

        case 2:
            stampaBiblioteca(&libri, nRighe);
        break;

        case 3:
            modificaLibro(&libri, nRighe);
        break;

        case 4: 
        break;
    }

    
    return 0;
}
