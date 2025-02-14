#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode();                           // Restituisce il puntatore a un nuovo nodo con un "data" random da 1 a 100
void createList(Node **head, int listLenght); // Creo la lista a lunghezza "listLenght"
void stampList(Node *head);                   // Stampo la lista
void addNodeTop(Node **head);                 // Aggiungo un nuovo nodo (con createNode) all'inizio della lista
void addNodeBottom(Node *head);               // Aggiungo un nuovo nodo (con createNode) alla fine della lista
void orderList(Node *head);                   // Ordina la lista in modo crescente
void pruneList(Node **head);                  // Libera la memoria e cancella il puntatore head

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
        printf("\n1 - Aggiungi un nodo in testa\n2 - Aggiungi un nodo in coda\n3 - Stampa la lista\n4 - Ordina la lista (crescente)\n5 - Esci\nScelta: ");
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
            orderList(head);
            break;
        case 5:
            printf("\n__ Termine programma __\n");
            pruneList(&head);
            exit(0);
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

void createList(Node **head, int listLenght)
{
    Node *pastNode = NULL;
    Node *currentNode = NULL;

    for (size_t i = 0; i < listLenght; i++)
    {
        currentNode = createNode();
        // Controllo l'esistenza della testa
        if (*head == NULL)
            // Se Non esiste la testa: assegno a testa il nuovo nodo
            *head = currentNode;
        else
            // Se Esiste la testa: assegno al Next del precedente nodo, il nodo appena creato
            pastNode->next = currentNode;
        // Assegno al nodo passato il nuovo nodo
        pastNode = currentNode;
    }
}

void addNodeTop(Node **head)
{
    Node *newNode = createNode();
    // Assegno al next del nuovo nodo la testa (vecchia testa)
    newNode->next = *head;
    // Faccio diventare il nodo creato la nuova testa
    *head = newNode;
}

void addNodeBottom(Node *head)
{
    // Scorro la lista
    while (head->next != NULL)
    {
        head = head->next;
    }
    // Creo il nuovo nodo alla fine della lista
    head->next = createNode();
}

// Ordina la lista in maniera crescente
void orderList(Node *head)
{
    return;
}

void pruneList(Node **head)
{
    // Creo puntatore temporaneo
    Node *temp = NULL;
    while (*head != NULL)
    {
        // assegno al temporaneo il nodo a cui punta head
        temp = *head;
        // scorro la lista con head
        *head = (*head)->next;
        // cancello il nodo al quale punta temp
        free(temp);
    }
    // Faccio puntare head a NULL
    *head = NULL;
}