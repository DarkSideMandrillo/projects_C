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
#include <string.h>
#define DIM 50
#define MAX 100
/*
PARTE 1
Leggi il file .csv e inserisci i dati dentro una lista
Crea una funzione per la stampa della lista e stampa su console
 */
typedef struct Node
{
    char nome[DIM];
    char citta[DIM];
    char via[DIM];
    int numAlunni;
    float valutazioneScuola;
    struct Node* next;
}Node;

void stampaLista(Node lista);

int main () {

    FILE *fp = fopen("elencoScuole.csv", "r");
    Node* head = NULL;
    if(fp == NULL){
        perror("--errore nell'apertura del file--");
    }
    else{
        // il primo era da togliere
        head = fscanf(fp, "%49[^,], %49[^,], %49[^,], %d, %f", head->nome, head->citta, head->via, &head->numAlunni, &head->valutazioneScuola);
        while (fscanf(fp, "%49[^,], %49[^,], %49[^,], %d, %f", head->nome, head->citta, head->via, &head->numAlunni, &head->valutazioneScuola)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Errore di allocazione memoria\n");
            return 1;
        }
        if (head == NULL) {
            head = newNode;
        } 
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    fclose(fp);

    printf("Lista delle scuole: \n");
    Node *current = head;
    while(current!= NULL){
        printf("Scuola: %s, Citta: %s, Via: %s, Numero alunni: %d, Valutazione della scuola: %f\n", current->nome, current->citta, current->via, current->numAlunni, current->valutazioneScuola);
        current = current->next;
    }
    /*
        PARTE 2
        Inserisci la scuola:
        "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
        all'INIZIO della linkedList
        */
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Errore di allocazione memoria\n");
        return 1;
    }
    strcpy(newNode->nome, "Istituto Nautico Amerigo Vespucci");
    strcpy(newNode->citta, "Genova");
    strcpy(newNode->via, "Via del Porto 45");
    newNode->numAlunni = 700;
    newNode->valutazioneScuola = 4.5;
    newNode->next = NULL;
    if (head == NULL) { //nessun if
        head = newNode;
    } 
    else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // metti alla fine
    }
    printf("\n Nuova scuola aggiunta: %s\n", newNode->nome);
    printf("Dati scuola: \nCitta: %s, Via: %s, Numero alunni: %d, Valutazione della scuola: %f\n", current->citta, current->via, current->numAlunni, current->valutazioneScuola);
    /*
    PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente
    */
    printf("\nLista ordinata per numero studenti:\n");
    
    
    
    return 0;
    }
}

