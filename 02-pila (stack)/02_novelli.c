#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    int row;
    char character;
    struct Nodo *next;
} Nodo;

int pilaVuota(Nodo *cima);
void push(Nodo **cima, int row);
int pop(Nodo **cima);
void stampaPila(Nodo *cima);
int peek(Nodo *cima);
Nodo *creaNodo(int row);

int main()
{
    Nodo *cima = NULL;
    FILE *fp = fopen("oop.txt", "r");

    int riga = 1;
    char str[256];
    while (fgets(str, 256, fp) != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                push(&cima, riga);
                printf("%c\n", str[i]);
            }
            if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                printf("%c\n", str[i]);
                pop(&cima);
                // stampaPila(cima);
            }
        }
        riga++;
    }
    if (pilaVuota(cima))
    {
        printf("vuota");
    }

    return 0;
}

// Funzioni per stack:
//  Funzione per controllare se la pila è vuota
int pilaVuota(Nodo *cima)
{
    return cima == NULL;
}

// Funzione per aggiungere un elemento alla pila (push)
void push(Nodo **cima, int row)
{
    Nodo *nuovoNodo = creaNodo(row);
    nuovoNodo->next = *cima;
    *cima = nuovoNodo;
}

// Funzione per rimuovere un elemento dalla pila (pop)
int pop(Nodo **cima)
{
    printf("%d\n", pilaVuota(*cima));
    if (pilaVuota(*cima))
    {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    Nodo *temp = *cima;
    int row = temp->row;
    *cima = (*cima)->next;
    free(temp);
    return row;
}

// Funzione per visualizzare la cima della pila
int peek(Nodo *cima)
{
    if (pilaVuota(cima))
    {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    return cima->row;
}

// Funzione per stampare tutti gli elementi della pila
void stampaPila(Nodo *cima)
{
    Nodo *corrente = cima;
    printf("Pila: ");
    while (corrente != NULL)
    {
        printf("%d ", corrente->row);
        corrente = corrente->next;
    }
    printf("\n");
}

Nodo *creaNodo(int row)
{
    Nodo *nuovoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuovoNodo->row = row;
    nuovoNodo->next = NULL;
    return nuovoNodo;
}