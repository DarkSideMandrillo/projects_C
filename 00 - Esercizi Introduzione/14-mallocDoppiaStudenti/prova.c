// Funzione stampa che accetta sia interi che float
#include <stdio.h>

void stampa(void* ptr, char tipo) {
    if (tipo == 'i') {
        // Cast a int* - Stampa la dereferenziazione di ptr
        printf("Intero: %d\n", *(int*)ptr);
    } else if (tipo == 'f') {
        // Cast a float* - Stampa la dereferenziazione di ptr
        printf("Float: %.2f\n", *(float*)ptr);
    }
}

int main() {
    int intero = 42;
    float virgola = 3.14;

    // Passiamo l'indirizzo dell'intero
    stampa(&intero, 'i');

    // Passiamo l'indirizzo del float
    stampa(&virgola, 'f');

    return 0;
}
