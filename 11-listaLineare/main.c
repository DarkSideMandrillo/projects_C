#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data;
  struct Node *next; // Usa 'struct Node *' per definire il puntatore al prossimo nodo
} Node;

Node *createNode(int value);
void addNodeBegin(Node **head, int value);
void addNodeEnd(Node **head, int value);
void printList(const Node *node);
void freeList(Node *head);

int main()
{
  //  Creo la lista
  Node *list = NULL;

  //  Aggiungo nodo alla lista
  addNodeBegin(&list, 10);
  addNodeBegin(&list, 20);
  addNodeEnd(&list, 30);

  printList(list);

  freeList(list);

  return 0;
}

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Errore nell'allocazione di memoria.\n");
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// Funzione per aggiungere un nodo all'inizio della lista
void addNodeBegin(Node **head, int value)
{
  Node *newNode = createNode(value);
  newNode->next = *head; // Il nuovo nodo punta alla vecchia testa
  *head = newNode;       // La testa diventa il nuovo nodo
}

// Funzione per aggiungere un nodo alla fine della lista
void addNodeEnd(Node **head, int value)
{
  Node *newNode = createNode(value);
  if (*head == NULL)
    *head = newNode; // Se la lista è vuota, il nuovo nodo diventa la testa
  else
  {
    Node *temp = *head;
    // Trova l'ultimo nodo della lista
    while (temp->next != NULL)
      temp = temp->next;
    // Aggiungi il nuovo nodo alla fine della lista
    temp->next = newNode;
  }
}

void printList(const Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

// Funzione per deallocare la memoria della lista
void freeList(Node *head)
{
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
