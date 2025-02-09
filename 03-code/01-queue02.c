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

// Structure to implement queue operations using a linked
// list
typedef struct Queue
{

  // Pointer to the front and the rear of the linked list
  Node *front, *rear;
} Queue;

Queue *createQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = NULL;
  return q;
}

Queue *createQueue();
int isEmpty(Queue *q);
void enqueue(Queue *q, int new_data);
void dequeue(Queue *q);
int getFront(Queue *q);
int getRear(Queue *q);

int main()
{
  Queue *q = createQueue();

  // Enqueue elements into the queue
  enqueue(q, 10);
  enqueue(q, 20);

  printf("Queue Front: %d\n", getFront(q));
  printf("Queue Rear: %d\n", getRear(q));

  // Dequeue elements from the queue
  dequeue(q);
  dequeue(q);

  // Enqueue more elements into the queue
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);

  // Dequeue an element from the queue
  dequeue(q);

  printf("Queue Front: %d\n", getFront(q));
  printf("Queue Rear: %d\n", getRear(q));

  return 0;
}

int isEmpty(Queue *q)
{
  if (q->front == NULL && q->rear == NULL)
    return 1;
  return 0;
}

void enqueue(Queue *q, int new_data)
{
  Node *newNode = createNode(new_data);

  if (isEmpty(q))
  {
    q->front = q->rear = newNode;
    return;
  }

  q->rear->next = newNode;
  q->rear = newNode;
}

void dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Coda Vuota");
    return;
  }

  Node *temp = q->front;
  q->front = q->front->next;

  free(temp);

  if (q->front == NULL) // Se la coda diventa vuota, resetta anche rear
    q->rear = NULL;
}

int getFront(Queue *q)
{
  // Checking if the queue is empty
  if (isEmpty(q))
  {
    printf("La coda è vuota\n");
    return INT_MIN;
  }
  return q->front->data;
}
int getRear(Queue *q)
{
  // Checking if the queue is empty
  if (isEmpty(q))
  {
    printf("La coda è vuota\n");
    return INT_MIN;
  }
  return q->rear->data;
}
