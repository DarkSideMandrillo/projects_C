#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    Node *head = NULL;
    Node *tempActual;
    Node *tempPrevious;

    srand((unsigned int)time(NULL));

    int count;
    printf("Inserisci la lunghezza della linked-list: ");
    scanf("%d", &count);

    for (size_t i = 0; i < count; i++)
    {
        Node *tempActual = (Node *)malloc(sizeof(Node));
        tempActual->data = (rand() % 100) + 1;
        tempActual->next = NULL;

        if (i == 0)
            head = tempActual;
        else
            tempPrevious->next = tempActual;

        tempPrevious = tempActual;
    }

    // ORDINAMENTO - bubble sort
    // Ordinamento tramite scambio dei puntatori
    Node *tempPrev;
    Node *tempCurr;
    Node *tempNext;
    int swapped;

    do
    {
        swapped = 0;               // Inizializza la variabile per controllare se sono stati effettuati scambi in questa iterazione.
        tempCurr = head;           // Puntatore al nodo corrente, inizialmente la testa della lista.
        tempNext = tempCurr->next; // Puntatore al nodo successivo rispetto al corrente.
        tempPrev = NULL;           // Puntatore al nodo precedente, inizialmente NULL perché non esiste un nodo prima della testa.

        while (tempNext != NULL)
        { // Continua finché ci sono nodi da confrontare.
            if (tempNext->data < tempCurr->data)
            {                // Verifica se i nodi sono nell'ordine sbagliato.
                swapped = 1; // Imposta il flag indicando che è avvenuto uno scambio.

                // Scambia i puntatori per invertire l'ordine dei nodi.
                tempCurr->next = tempNext->next; // Il nodo corrente punta al nodo successivo al nodo "next".
                tempNext->next = tempCurr;       // Il nodo "next" punta al nodo corrente.

                // Gestione del puntatore `head` se lo scambio coinvolge la testa della lista.
                if (tempCurr == head)
                {
                    head = tempNext; // Aggiorna la testa della lista al nodo "next".
                }
                else
                {
                    tempPrev->next = tempNext; // Aggiorna il nodo precedente per collegarsi al nodo "next".
                }

                // Aggiorna i puntatori per la prossima iterazione dopo lo scambio.
                tempPrev = tempNext;       // Il nodo "next" diventa il nuovo "prev".
                tempNext = tempCurr->next; // Il nodo corrente rimane invariato, si aggiorna solo "next".
            }
            else
            {
                // Nessuno scambio: sposta semplicemente i puntatori in avanti.
                tempPrev = tempCurr;       // Il nodo corrente diventa il nuovo "prev".
                tempCurr = tempCurr->next; // Sposta il nodo corrente in avanti.
                tempNext = tempNext->next; // Sposta il nodo successivo in avanti.
            }
        }

    } while (swapped); // Ripete il ciclo finché viene effettuato almeno uno scambio.

    // STAMPO
    Node *cursor = head;
    while (cursor != NULL)
    {
        printf("Valore: %d\n", cursor->data);
        cursor = cursor->next;
    }
    // LIBERO MEMORIA
    cursor = head;
    while (cursor != NULL)
    {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return 0;
}