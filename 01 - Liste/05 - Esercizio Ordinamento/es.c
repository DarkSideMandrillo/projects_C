
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 20

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int main()
{
    int n = 60;  // Numero di nodi che si vuole avere
    Node* primo = NULL;
    Node* attuale = NULL;
    srand(time(NULL)); //funzione che permette di generare numeri casuali

    for (int i = 0; i < n; i++) {
        Node* NuovoNodo = (Node *)malloc(sizeof(Node)); //malloc peer la generazione dei nodi
        if (NuovoNodo == NULL) {  // Controllo che l'allocazione sia riuscita
            printf("Errore di allocazione della memoria\n");
            return 1;
        }
        NuovoNodo->data = MIN + rand() % (MAX-MIN+1);  // assegno a data un valore casuale compreso tra min e max
        NuovoNodo->next = NULL;
        
        if (primo == NULL || primo->data >= NuovoNodo->data) {
            NuovoNodo->next = primo; //
            primo = NuovoNodo;
        } else {
            Node* current = primo;
            while (current->next != NULL && current->next->data < NuovoNodo->data) {
                current = current->next;
            }
            NuovoNodo->next = current->next;
            current->next = NuovoNodo;
        }
    }
    
    // Stampo i dati della lista
    attuale = primo; //pongo il nodo corrente uguale a quello di testa così che io riesca a effettuare la stampa partendo da esso
    while (attuale != NULL) {
        printf("%d ", attuale->data);
        attuale = attuale->next;
    }

    // Libero la memoria allocata
    attuale = primo;
    while (attuale != NULL) {
        Node* temp = attuale;
        attuale = attuale->next;
        free(temp);
    }

    return 0; 
}
