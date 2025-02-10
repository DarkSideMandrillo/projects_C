#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int row;           // Riga
    int col;           // Colonna
    struct Nodo *next; // Puntatore al nodo successivo
} Nodo;

// Prototipi delle funzioni
int isSafe(Nodo *cima, int row, int col);
void push(Nodo **cima, int row, int col);
void pop(Nodo **cima);
void stampaSoluzione(Nodo *cima);
int pilaVuota(Nodo *cima);

// Funzione principale
int main()
{
    Nodo *cima = NULL; // Stack inizializzato vuoto
    int row = 0;       // Riga corrente
    int col = 0;       // Colonna corrente

    while (1)
    {
        // Trova una colonna valida nella riga corrente
        while (col < 8 && !isSafe(cima, row, col))
        {
            col++;
        }

        if (col < 8)
        {
            // Posiziona una regina
            push(&cima, row, col);
            row++;   // Passa alla riga successiva
            col = 0; // Ricomincia dalla prima colonna
        }
        else
        {
            // Backtracking: rimuovi la regina precedente
            if (pilaVuota(cima))
            {
                // Non ci sono più mosse, termina
                break;
            }
            Nodo *ultimo = cima; // Ottieni l'ultimo nodo
            row = ultimo->row;
            col = ultimo->col + 1;
            pop(&cima); // Rimuovi l'ultimo nodo
        }

        // Se tutte le regine sono posizionate, stampa la soluzione
        if (row == 8)
        {
            stampaSoluzione(cima);
            // Backtracking per trovare altre soluzioni
            Nodo *ultimo = cima;
            row = ultimo->row;
            col = ultimo->col + 1;
            pop(&cima);
        }
    }

    return 0;
}

// Controlla se è sicuro posizionare una regina
int isSafe(Nodo *cima, int row, int col)
{
    Nodo *current = cima;
    while (current != NULL)
    {
        int r = current->row;
        int c = current->col;
        // Controlla colonna, diagonale principale e secondaria
        if (c == col || abs(r - row) == abs(c - col)) // abs: numero assoluto
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

// Aggiunge una regina alla pila
void push(Nodo **cima, int row, int col)
{
    Nodo *nuovoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuovoNodo->row = row;
    nuovoNodo->col = col;
    nuovoNodo->next = *cima;
    *cima = nuovoNodo;
}

// Rimuove una regina dalla pila
void pop(Nodo **cima)
{
    if (pilaVuota(*cima))
    {
        printf("Errore: pila vuota\n");
        exit(1);
    }
    Nodo *temp = *cima;
    *cima = (*cima)->next;
    free(temp);
}

// Controlla se la pila è vuota
int pilaVuota(Nodo *cima)
{
    return cima == NULL;
}

// Stampa una soluzione
void stampaSoluzione(Nodo *cima)
{
    char board[8][8] = {0};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = '.';
        }
    }

    Nodo *current = cima;
    while (current != NULL)
    {
        board[current->row][current->col] = 'Q';
        current = current->next;
    }

    printf("\nSoluzione trovata:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
