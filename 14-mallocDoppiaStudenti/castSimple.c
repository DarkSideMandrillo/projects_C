#include <stdio.h>
#include <stdlib.h>

// Dichiarazione della funzione crea, che accetta un carattere per specificare il tipo
// di variabile da creare (char o int) e ritorna un puntatore void*.
void *crea(char type);

int main() {
    // Dichiarazione di un puntatore a char
    char *c;
    // Chiamata alla funzione crea con il parametro 'c', che indica la creazione di un char
    // Il puntatore restituito da crea (void*) viene castato a char*
    c = (char*) crea('c');
    // Assegnazione di un valore al carattere puntato
    *c = 'f';

    // Dichiarazione di un puntatore a int
    int *i;
    // Chiamata alla funzione crea con il parametro 'i', che indica la creazione di un int
    // Il puntatore restituito da crea (void*) viene castato a int*
    i = (int*) crea('i');
    // Assegnazione di un valore all'intero puntato
    *i = 33;

    // Stampa del valore del carattere
    printf("%c\n", *c);
    // Stampa del valore dell'intero
    printf("%d", *i);

    // Liberazione della memoria
    free(c);
    free(i);
    
    return 0;
}

// Implementazione della funzione crea, che alloca memoria per un tipo di dato specifico
void *crea(char type) {
    // Se il tipo richiesto è un char ('c'), viene allocata memoria per un singolo char
    if (type == 'c')
        return malloc(sizeof(char));  // malloc alloca memoria per 1 byte (char)

    // Se il tipo richiesto è un int ('i'), viene allocata memoria per un singolo int
    if (type == 'i')
        return malloc(sizeof(int));  // malloc alloca memoria per un intero (4 byte su molti sistemi)

    // Se viene passato un tipo non riconosciuto, non viene allocata memoria
    // return NULL per gestire tipi non validi.
    return NULL;
}

// Commenti generati con ChatGPT... Urca quanto è prolisso!