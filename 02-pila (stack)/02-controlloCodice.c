// Controllo peso parentesi in un file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack
{
    char bracket;
    int riga;
    struct Stack *next;
} Stack;

Stack *creaNodo(int bracket);
int pilaVuota(Stack *cima);
void push(Stack **cima, int bracket);
char pop(Stack **cima);
int peek(Stack *cima);
void stampaPila(Stack *cima);
int bracketControl(char bracket);

int main()
{
    Stack *pila = NULL;
    int ch;
    bool openStr = false;
    int riga = 1;
    char nomeFile[1024] = "oop.txt";
    FILE *fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        perror("Errore nell'apertura del FILE!");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            riga += 1;
        if (ch == '"' && openStr == false)
            openStr = true;
        else if (ch == '"' && openStr == true)
            openStr = false;

        if ((ch == '(' || ch == '[' || ch == '{') && openStr == false)
            push(&pila, ch);

        if ((ch == ')' || ch == ']' || ch == '}') && openStr == false)
        {
            char tempChar;
            if ((tempChar = pop(&pila)) != 0)
            {
                if (bracketControl(ch) != bracketControl(tempChar))
                {
                    printf("Parentesi discordanti alla riga %d\n", riga);
                    fclose(fp);
                    return EXIT_FAILURE; // Blocca il programma
                }
            }
            else
            {
                printf("Errore di sintassi alla riga %d\n", riga);
                fclose(fp);
                return EXIT_FAILURE; // Blocca il programma
            }
        }
    }
    if (!pilaVuota(pila))
    {
        printf("\n\n!!ERRORE - PARENTESI NON CHIUSA\n");
    }
    else
    {
        printf("\n\nFINE PROGRAMMA\n");
        printf("NUMERO TOT RIGHE: %d", riga);
    }

    fclose(fp);
}

// Funzione per creare un nuovo nodo
Stack *creaNodo(int bracket)
{
    Stack *nuovaPila = (Stack *)malloc(sizeof(Stack));
    if (nuovaPila == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovaPila->bracket = bracket;
    nuovaPila->next = NULL;
    return nuovaPila;
}

// Funzione per controllare se la pila è vuota
int pilaVuota(Stack *cima)
{
    return cima == NULL;
}

// Funzione per aggiungere un elemento alla pila (push)
void push(Stack **cima, int bracket)
{
    Stack *nuovaPila = creaNodo(bracket);
    nuovaPila->next = *cima;
    *cima = nuovaPila;
}

// Funzione per rimuovere un elemento dalla pila (pop)
char pop(Stack **cima)
{
    if (pilaVuota(*cima))
    {
        printf("Errore: la pila è vuota\n");
        return 0;
    }
    Stack *temp = *cima;
    int bracket = temp->bracket;
    *cima = (*cima)->next;
    free(temp);
    return bracket;
}

// Funzione per visualizzare la cima della pila
int peek(Stack *cima)
{
    if (pilaVuota(cima))
    {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    return cima->bracket;
}

// Funzione per stampare tutti gli elementi della pila
void stampaPila(Stack *cima)
{
    Stack *corrente = cima;
    printf("Pila: ");
    while (corrente != NULL)
    {
        printf("%d ", corrente->bracket);
        corrente = corrente->next;
    }
    printf("\n");
}

int bracketControl(char bracket)
{
    // 0-tonde, 1-quadre, 2-graffe
    if (bracket == ')' || bracket == '(')
        return 0;
    if (bracket == ']' || bracket == '[')
        return 1;
    if (bracket == '}' || bracket == '{')
        return 2;
    return -1;
}