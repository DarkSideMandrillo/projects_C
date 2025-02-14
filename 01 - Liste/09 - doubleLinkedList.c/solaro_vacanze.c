
/*
-Aggiungere nodo alla fine
-Aggiungere nodo all'inizio
-Ricercare un nodo dal valore di un dato
-Cancellare un nodo
-Ordinare la lista*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIM 50

typedef struct Node
{
    struct Node* previous;
    struct Node* next;
    int data;   
}Node;

void creaLista(Node** head, int dim, int dati[]);
Node* creaNodo(int data);
void stampaLista(Node* head);
void appendNode(Node** head, int data);
void addTop(Node** head, int data);
Node* cercaNodoByDato(Node* head, int dato);
bool cancellaNodo(Node** head, int datoDaCancellare);
void ordinaLista(Node** head);
void freeList(Node* head);


int main()
{
    Node* head = NULL;

    // Creazione della lista
    int dataList[DIM];
    for (int i = 0; i < DIM; i++) {
        dataList[i] = DIM - i;  // Popoliamo con dati non ordinati
    }

    creaLista(&head, DIM, dataList);
    printf("Lista iniziale:\n");
    stampaLista(head);

    // Aggiungere un nodo alla fine
    printf("Aggiunta di 100 alla fine:\n");
    appendNode(&head, 100);
    stampaLista(head);

    // Aggiungere un nodo all'inizio
    printf("Aggiunta di 0 all'inizio:\n");
    addTop(&head, 0);
    stampaLista(head);

    // Ricercare un nodo per valore
    int valoreCercato = 25;
    Node* nodoTrovato = cercaNodoByDato(head, valoreCercato);
    if (nodoTrovato != NULL) {
        printf("Nodo trovato con valore %d\n", nodoTrovato->data);
    } else {
        printf("Nodo con valore %d non trovato\n", valoreCercato);
    }

    // Cancellare un nodo
    int valoreDaCancellare = 25;
    if (cancellaNodo(&head, valoreDaCancellare)) {
        printf("Nodo con valore %d cancellato:\n", valoreDaCancellare);
    } else {
        printf("Nodo con valore %d non trovato per cancellazione\n", valoreDaCancellare);
    }
    stampaLista(head);

    // Ordinare la lista
    printf("Lista ordinata:\n");
    ordinaLista(&head);
    stampaLista(head);

    // Libera la memoria
    freeList(head);
    return 0;
}

Node* creaNodo(int data)
{
    Node* newNode=(Node*) malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->previous=NULL;
    newNode->data=data;
    return newNode;
}

void creaLista(Node** head, int dim, int dati[])
{
    Node* previus=NULL;
    for (size_t i = 0; i < dim; i++)
    {
        Node* newNode=creaNodo(dati[i]);
        if(previus==NULL)
            *head=newNode;
        else
            previus->next=newNode;
            newNode->previous=previus;
        previus=newNode;
    }
    
}

void stampaLista(Node* head)
{
    printf("LISTA:\n");
    while (head!=NULL)
    {
        printf("%d\n", head->data);
        head=head->next;
    }
    printf("\n");    
}

void appendNode(Node** head, int data)
{
    Node* newNode=creaNodo(data);
    if (*head==NULL)
    {
        *head=newNode;
        return;         //return vuoto serve ad uscire dalla funzione, si poteva anche scrivere
    }                   // il resto della funzione in una else
    
    Node* current=*head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->previous=current;
}

void addTop(Node** head, int data)
{
    Node* newNode=creaNodo(data);
    newNode->next=*head;
    (*head)->previous=newNode;
    *head=newNode;
}

Node* cercaNodoByDato(Node* head, int dato)
{
    Node* nodoTrovato=NULL;
    bool trovato=false;
    while (head!=NULL&&!trovato)
    {
        if (head->data==dato)
        {
            nodoTrovato=head;
            trovato=true;
        }
        head=head->next;
    }
    return nodoTrovato;
    
}

bool cancellaNodo(Node** head, int datoDaCancellare)
{
    bool cancellato=false;
    Node* nodoDaCancellare=cercaNodoByDato((*head), datoDaCancellare);
    if(nodoDaCancellare!=NULL)
    {
        if(nodoDaCancellare->previous!=NULL)
            nodoDaCancellare->previous->next=nodoDaCancellare->next;
        else
            (*head)=nodoDaCancellare->next;

        if(nodoDaCancellare->next!=NULL)
            nodoDaCancellare->next->previous=nodoDaCancellare->previous;
        cancellato=true;
        //!! Manca la free della memo
    }
    return cancellato;
}

void ordinaLista(Node** head)
{
    Node* current=(*head);
    bool ordinato=false;
    while (!ordinato)
    {
        ordinato=true;
        current=(*head);
        while (current->next!=NULL || current->next!=NULL) //!! ?
        {
            if(current->data > current->next->data)
            {
                //inverti
                int appoggio=current->data;
                current->data=current->next->data;
                current->next->data=appoggio;
                ordinato=false;
            }
        }        
        
    }
    
}


void freeList(Node* head)
{
    Node* temp;
    while (head!=NULL)
    {
        temp=head;
        free(temp);
        head=head->next;
    }
    
}

