
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode();
void createList(Node **head, int listLenght);
void stampList(Node *head);
void addNodeTop(Node **head);
void addNodeBottom(Node *head);
//void orderList(Node *head);
void pruneList(Node **head);

int main()
{
    Node *head = NULL;
    int listLenght = 0;
    int choice = 0;

    srand((unsigned int)time(NULL));

    printf("Inserisci la lunghezza della lista iniziale da creare: ");
    scanf("%d", &listLenght);

    createList(&head, listLenght);

    while (choice != 4)
    {
        printf("\n1 - Aggiungi un nodo in testa\n2 - Aggiungi un nodo in coda\n3 - Stampa la lista\n4 - Esci\nScelta: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNodeTop(&head);
            break;

        case 2:
            addNodeBottom(head);
            break;
        case 3:
            stampList(head);
            break;

        case 4:
            printf("\n__ Termine programma __\n");
            pruneList(&head);
            break;

        default:
            printf("\ninserimento errato\n");
            break;
        }
    }
}

Node *createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        // Errore: memoria non allocata
        fprintf(stderr, "Errore: memoria non allocata!\n");
        return NULL;
    }

    newNode->data = (rand() % 100) + 1;
    newNode->next = NULL;

    return newNode;
}

void createList(Node **head, int listLenght)
{
    Node* nodePrevius = NULL;

    for (size_t i = 0; i < listLenght; i++)
    {
        Node *newNode = createNode();
        
        if (*head == NULL)
            *head = newNode;
        else
            nodePrevius->next=newNode;
        
        nodePrevius = newNode;
    }
}

void stampList(Node *head)
{
    printf("\nLista: [");
    
    while (head != NULL)
    {
        // Stampa il valore del nodo
        printf("%d", head->data);

        // Se il nodo successivo esiste, stampa il trattino
        if (head->next != NULL)
            printf(" - ");

        head = head->next;
    }
    printf("]\n");   
}

void addNodeTop(Node **head)
{
    Node *newNode = createNode();
    newNode->next = *head;
    *head = newNode;
}

void addNodeBottom(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = createNode();
    
}

// void orderList(Node *head);

void pruneList(Node **head)
{
    Node* temp = NULL;
    while (*head != NULL)
    {
        temp = head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}