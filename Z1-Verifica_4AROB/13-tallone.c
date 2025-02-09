
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
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{   //definisco la struttura libro
    char titolo[100];
    char autore[100];
    int copie;
}Libro;
int contaRighe(FILE *fp){
    int righe = 0;
    char buffer[1024]; //serve per salvare le righe del file
    //!! togli prima riga
    while(fgets(buffer,1024,fp)){
        righe++;
    }
    rewind(fp);//!! da fare prima di return
    return righe;
    
}

void caricaDatiFile(FILE *fp, Libro *array_libri){
    int k = 0;
    char buffer[1024];
    while(fgets(buffer,1024,fp)){
        char *token = strtok(buffer, ","); //token è una variabile in cui salvo ogni parte della riga separate dalle virgole
        strcpy(array_libri[k].titolo, token);
        token = strtok(NULL, ",");
        strcpy(array_libri[k].autore, token);
        token = strtok(NULL, ",");
        array_libri[k].copie = atoi(token);
        k++;

    }


}

void bubbleSort(Libro *array,int dim){ //!! mancava void
    int i, j;
    Libro temp;
    for(i = 0; i < dim - 1; i++){
        for(j = 0; j < dim - i - 1; j++){
            if(array[j].copie > array[j + 1].copie){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int main(){
    // Apre il file
    FILE *fp = fopen("Libri.csv", "r"); //apro il file
    if(fp == NULL){
        perror("Errore apertura file\n");
        return 1;
    }
int nLibri = contaRighe(fp);



Libro *array_libri;
array_libri = (Libro *)calloc(nLibri, sizeof(Libro)); //alloco dinamicamene la memoria facendo il casting e calcolando la dimensione per ogni Libro

caricaDatiFile(fp,array_libri);

fclose(fp); //chiudo il file

while(true){
    int scelta;
    printf("\nMenu:\n");
    printf("1. Aggiungi libro\n");
    printf("2. Visualizza biblioteca\n");
    printf("3. Modifica libro\n");
    printf("4. Ordina biblioteca\n");
    printf("5. Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta) //controllo la scelta
    {
    case 1:
    // Aggiunta libro
    int aggiunta;
    printf("inserisci il numero di libri da aggiungere: \n");
    scanf("%d", &aggiunta);
    array_libri = realloc(array_libri, (nLibri + aggiunta) * sizeof(Libro)); //rialloco la memoria
    for(int i = nLibri; i < nLibri + aggiunta; i++){ //scorro i libri partendo dall'ultimo inserito
        strcpy(array_libri[i].autore, "pietro tallone");
        strcpy(array_libri[i].titolo, "libro aggiunto");
        array_libri[i].copie = 2;
    }
    nLibri += aggiunta; //modifico il numero totale di libri
        break;

    case 2:
    // Visualizza biblioteca
    printf("\nBiblioteca:\n");
    for(int i = 0; i < nLibri; i++){
        printf("Titolo: %s\nAutore: %s\nCopie: %d\n", array_libri[i].titolo, array_libri[i].autore, array_libri[i].copie);
        printf("\n");
    }
    break;

    case 3:
    // Modifica libro
    char titolo[100];
    bool tro = false;
    printf("Inserisci il titolo del libro da modificare: \n");
    scanf("%s", titolo);
    for(int i = 0; i < nLibri; i++){  //scorro tutti i libri
        if(strcmp(array_libri[i].titolo, titolo) == 0){ //controllo se il titolo è quello da modificare
            tro = true;
            printf("Inserisci il numero di copie da aggiungere: \n");
            scanf("%d", &array_libri[i].copie);
            break;
        }
        printf("Inserisci il numero di copie da aggiungere: \n");
            scanf("%d", &array_libri[i].copie); //modifico il numero di copie
            break;//!!??
        }
        if(!tro)
        printf("il libro non esiste");
        break;

        case 4:
        // Ordina biblioteca
        bubbleSort(array_libri, nLibri); //chiamo il bubble sort per ordinare i libri

        break;

        case 5:
        // Esci
        printf("stai uscendo\n");
        return 0;


    }
    
    }
    free(array_libri); //disalloco lo spazio in memoria
    return 0;
}

