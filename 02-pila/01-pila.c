#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per un nodo della pila
typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

// Funzione per creare un nuovo nodo
Nodo* creaNodo(int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = NULL;
    return nuovoNodo;
}

// Funzione per controllare se la pila è vuota
int pilaVuota(Nodo* cima) {
    return cima == NULL;
}

// Funzione per aggiungere un elemento alla pila (push)
void push(Nodo** cima, int dato) {
    Nodo* nuovoNodo = creaNodo(dato);
    nuovoNodo->prossimo = *cima;
    *cima = nuovoNodo;
}

// Funzione per rimuovere un elemento dalla pila (pop)
int pop(Nodo** cima) {
    if (pilaVuota(*cima)) {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    Nodo* temp = *cima;
    int dato = temp->dato;
    *cima = (*cima)->prossimo;
    free(temp);
    return dato;
}

// Funzione per visualizzare la cima della pila
int peek(Nodo* cima) {
    if (pilaVuota(cima)) {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    return cima->dato;
}

// Funzione per stampare tutti gli elementi della pila
void stampaPila(Nodo* cima) {
    Nodo* corrente = cima;
    printf("Pila: ");
    while (corrente != NULL) {
        printf("%d ", corrente->dato);
        corrente = corrente->prossimo;
    }
    printf("\n");
}

int main() {
    Nodo* pila = NULL; // Inizializza la pila

    // Esempio di utilizzo
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);

    stampaPila(pila);

    printf("Elemento rimosso: %d\n", pop(&pila));
    printf("Elemento in cima: %d\n", peek(pila));

    stampaPila(pila);

    return 0;
}
