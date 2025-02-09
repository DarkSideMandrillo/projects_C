#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data);

int main()
{
    // Creo il nodo di TESTA
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;   // Gli assegno 10 come data
    head->next = NULL; // Gli assegno NULL al puntatore del prox nodo

    // Creo il nodo SECONDO
    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 20;   // Gli assegno 20 come data
    second->next = NULL; // Gli assegno NULL al puntatore del prox nodo

    // Faccio puntare il nodo TESTA all'indirizzo del nodo SECONDO
    head->next = second;

    // Creo il nodo TERZO
    Node *third = createNode(10);


    // Faccio puntare il nodo SECONDO all'indirizzo del nodo TERZO
    second->next = third;

    second = NULL;
    third = NULL;

    // Stampo i dati della lista
    Node *current = head;
    while (current != NULL)
    {
        printf("Dato: %d\n", current->data);
        current = current->next;
    }

    // Libero la memoria allocata
    current = head;
    Node *currentTemp = NULL;
    while (current != NULL)
    {
        currentTemp = current;
        current = current->next;
        free(currentTemp);
    }
    current = NULL;
    head = NULL;
    currentTemp = NULL;
}

Node* createNode()
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data; // Fate un random al posto di inserire un dato specifica
    newNode->next=NULL;
    return newNode;
}