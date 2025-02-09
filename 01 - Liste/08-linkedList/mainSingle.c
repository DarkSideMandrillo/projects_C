#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
   
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
    newNode->previous = NULL;
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
}

// Funzione per stampare la lista
void printListCoda(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    // Stampare la lista
    printf("Lista collegata: ");
    printListCoda(head);

    // Liberare la memoria
    freeList(head);

    return 0;
}
