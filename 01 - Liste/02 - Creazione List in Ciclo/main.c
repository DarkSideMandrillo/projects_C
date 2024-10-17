#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    // La testa deve puntare a NULL (nel caso non volessi aver nessu nodo in lista)
    Node *head = NULL;
    Node *tempActual;
    Node *tempPrevious;

    int count = 5;
    // Assegno una porzione di memoria di grandezza Node al puntatore head
    head = (Node *)malloc(sizeof(Node)); 
    head->next = NULL;
    head->data = 0;

    // Assegno a nodoPrecedente il puntatore testa
    tempPrevious = head;

    // Entro in Ciclo per creare count nuovi nodi
    for (size_t i = 1; i < count; i++)
    {
        // Creo il nodo
        Node *tempActual = (Node *)malloc(sizeof(Node));
        tempActual->data = i;
        tempActual->next = NULL; // Gli assegno NULL al puntatore del prox nodo

        // Assegno al next del precedente nodo l'indirizzo del nuovo nodo
        tempPrevious->next = tempActual;

        // NodoPrecedente ora deve puntare al nodoAttuale appena creato
        // così potremmo ricreare un nuovo nodoAttuale mantenendo in memoria
        // quello creato in precedenza
        tempPrevious = tempActual;
    }

    Node *cursor = head;
    while (cursor != NULL)
    {
        printf("Valore: %d\n", cursor->data);
        cursor = cursor->next;
    }

    cursor = head;
    while (cursor != NULL)
    {
        Node* temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return 0;
}