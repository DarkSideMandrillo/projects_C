/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |      

CleanCode = Commenti nel codice, Nome variabili corrette, codice non ripetuto, logica ottimizzata
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM 100

typedef struct School{
    char name[DIM];
    char city[DIM];
    char address[DIM];
    int nStd;
    float scoreSchool;
    struct School *next;
}School;

void stampaLista(School* head);

int main(){
    char nomeFile[] = "elencoScuole.csv";

    /*
    PARTE 1
    Leggi il file .csv e inserisci i dati dentro una lista
    Crea una funzione per la stampa della lista e stampa su console
    */

    FILE *fp = fopen(nomeFile,"r");

    if(fp == NULL){
        return 0;
    }
    int index = 0;


    char str[1024];
    while(fgets(str,1024,fp)!= NULL){ //non serve
        index++;
    }

    fclose(fp);

    fp = fopen(nomeFile,"r");
    //salta la rpima linea
    fgets(str,1024,fp);

    School *head = NULL;
    School *current = NULL;
    for(int i = 0; i<index; i++){
        School *newSchool = (School*) malloc(sizeof(School));
        newSchool->next = NULL;
        
        fscanf(fp,"%99[^,],%[^,],%[^,],%d,%f",newSchool->name,newSchool->city,newSchool->address, &newSchool->nStd, &newSchool->scoreSchool);

        if(head == NULL){
            head = newSchool;
        }else{
            current->next = newSchool;
        }

        current = newSchool;
    }

    stampaLista(head);
    printf("\n\n\n\n");

    /*
    PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList
    */

    School *newHead = (School*) malloc(sizeof(School));
    strcpy(newHead->name,"Istituto Nautico Amerigo Vespucci");
    strcpy(newHead->city,"Genova");
    strcpy(newHead->address,"Via del Porto 45");
    newHead->nStd = 700;
    newHead->scoreSchool = 4.5;

    newHead->next = head;

    head = newHead;

    stampaLista(head);    
    printf("\n\n\n\n");

    /*
    PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente
    */

    bool swap = true;
    School *last = NULL;

    while(swap){
        swap = false; // manca il true. così fa solo un iterazione
        current = head;
        while(current->next != last){
            if(current->nStd > current->next->nStd){
                int temp = current->nStd;
                current->nStd = current->next->nStd;
                current->next->nStd = temp;  // ma devi cambiare tutti i dati
            }
            current = current->next;
        }

        last = current; 
    }
    

   stampaLista(head);

   return 0;
}

void stampaLista(School* head){
    School *current = head;
    while(current != NULL){
        printf("%s,%s,%s,%d,%f\n",current->name,current->city,current->address, current->nStd, current->scoreSchool);
        current = current->next;
    }
}
