#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Funzione per creare un nuovo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Errore di allocazione della memoria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Funzione per aggiungere un nodo alla fine della lista
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Funzione per stampare la lista in avanti
void printListForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Funzione per stampare la lista all'indietro
void printListBackward(struct Node* tail) {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Funzione per trovare la coda della lista
struct Node* findTail(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// Funzione per liberare la memoria della lista
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Aggiungere nodi alla lista
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // Stampare la lista in avanti
    printf("Lista collegata (in avanti): ");
    printListForward(head);

    // Stampare la lista all'indietro
    struct Node* tail = findTail(head);
    printf("Lista collegata (all'indietro): ");
    printListBackward(tail);

    // Liberare la memoria
    freeList(head);

    return 0;
}
