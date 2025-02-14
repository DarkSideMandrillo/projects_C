#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Node structure representing a single node in the linked
// list
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int new_data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = new_data;
  new_node->next = NULL;
  return new_node;
}

int isEmpty(Node *front, Node *rear);
void enqueue(Node **front, Node **rear, int new_data);
void dequeue(Node **front, Node **rear);
int getFront(Node *front, Node *rear);
int getRear(Node *front, Node *rear);

int main()
{
  Node *front = NULL;
  Node *rear = NULL;

  // Enqueue elements into the queue
  enqueue(&front, &rear, 10);
  enqueue(&front, &rear, 20);

  printf("Queue Front: %d\n", getFront(front, rear));
  printf("Queue Rear: %d\n", getRear(front, rear));

  // Dequeue elements from the queue
  dequeue(&front, &rear);
  dequeue(&front, &rear);

  // Enqueue more elements into the queue
  enqueue(&front, &rear, 30);
  enqueue(&front, &rear, 40);
  enqueue(&front, &rear, 50);

  // Dequeue an element from the queue
  dequeue(&front, &rear);

  printf("Queue Front: %d\n", getFront(front, rear));
  printf("Queue Rear: %d\n", getRear(front, rear));

  return 0;
}

int isEmpty(Node *front, Node *rear)
{
  if (front == NULL && rear == NULL)
    return 1;
  return 0;
}

void enqueue(Node **front, Node **rear, int new_data)
{
  Node *newNode = createNode(new_data);

  if (isEmpty(*front, *rear))
  {
    *front = *rear = newNode;
    return;
  }

  (*rear)->next = newNode;
  *rear = newNode;
}

void dequeue(Node **front, Node **rear)
{
  if (isEmpty(*front, *rear))
  {
    printf("Coda Vuota");
    return;
  }

  Node *temp = *front;
  *front = (*front)->next;

  free(temp);

  if (*front == NULL) // Se la coda diventa vuota, resetta anche rear
    *rear = NULL;
}

int getFront(Node *front, Node *rear)
{
  // Checking if the queue is empty
  if (isEmpty(front, rear))
  {
    printf("La coda è vuota\n");
    return INT_MIN;
  }
  return front->data;
}
int getRear(Node *front, Node *rear)
{
  // Checking if the queue is empty
  if (isEmpty(front, rear))
  {
    printf("La coda è vuota\n");
    return INT_MIN;
  }
  return rear->data;
}
