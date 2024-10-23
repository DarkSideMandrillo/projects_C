#include <stdio.h>
#include <stdlib.h>

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

    int count = 5;

    for (size_t i = 0; i < count; i++)
    {
        Node *tempActual = (Node *)malloc(sizeof(Node));
        tempActual->data = i;
        tempActual->next = NULL;

        if (i==0)
            head=tempActual;
        else
            tempPrevious->next = tempActual;           

        tempPrevious = tempActual;
    }

    // Aggiungo un nodo all'inizio
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = 66;
    newNode->next = head;
    head = newNode;

    // Aggiungo un nodo alla fine
    Node *cursor = head;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = 99;
    newNode->next = NULL;
    while (cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    cursor->next = newNode;

    // STAMPO
    cursor = head;
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