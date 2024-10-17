// PUNTATORE A PUNTATORI

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void createNode(Node **head);

int main()
{
    Node *head = NULL;
    createNode(&head); // Passo l'indirizzo di head

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

void createNode(Node **head)
{
    int count = 5;
    Node *tempActual;
    Node *tempPrevious;

    for (size_t i = 0; i < count; i++)
    {
        Node *tempActual = (Node *)malloc(sizeof(Node));
        tempActual->data = i;
        tempActual->next = NULL;

        // Al primo giro, tempActual diventa la testa
        if (i == 0)
            *head = tempActual;
        else
            tempPrevious->next = tempActual;
        tempPrevious = tempActual;
    }
}