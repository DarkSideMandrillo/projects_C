#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int row;
    int col;
    struct Node *next;
} Node;

bool isSafe(Node *top, int row, int col);
void printSolution(Node *top);
bool isEmpty(Node *top);
void push(Node **top, int row, int col);
int pop(Node **top);

int main()
{
    int col = 0;
    int row = 0;
    Node *top = NULL;
    while (true)
    {
        while (row < 8)
        {
            while (col < 8)
            {
                if (isSafe(top, row, col))
                {
                    push(&top, row, col);
                    row++;
                    col = 0;
                }
                else
                    col++;
            }
            col = pop(&top) + 1;
            row--;
            if (row == -1)
            {
                exit(0);
            }
        }
        printSolution(top);
    }
}

// Controllo se la posizione richiesta è sicura
bool isSafe(Node *top, int row, int col)
{
    if (isEmpty(top))
        return true;

    while (top->next != NULL)
    {
        if (top->col == col || top->row == row || abs(top->col - col) == abs(top->row - row))
            return false;
        top = top->next;
    }
    return true;
}

bool isEmpty(Node *top)
{
    return top == NULL;
}

void push(Node **top, int row, int col)
{
    // Creo e popolo NewNode
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->col = col;
    newNode->row = row;
    newNode->next = NULL;
    // Aggiungo sopra lo stack. al primo gito top è null
    newNode->next = *top;
    *top = newNode;
}

// ritorna la colonna nella quale è stato cancellato il nodo
int pop(Node **top)
{
    Node *temp = *top;
    int col = (*top)->col;
    *top = (*top)->next;
    free(temp);
    return col;
}

void printSolution(Node *top)
{
    char board[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';

    while (top->next != NULL)
    {
        board[top->row][top->col] = 'Q';
        top = top->next;
    }
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            printf("%c ", board[i][j]); // Stampa con spazio per migliorare la leggibilità.
        }
        printf("\n");
    }
    printf("--------\n");
}