/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |      

CleanCode = Commenti nel codice, Nome variabili corrette, codice non ripetuto, logica ottimizzata
*/
/*
PARTE 1
Leggi il file .csv e inserisci i dati dentro una lista
Crea una funzione per la stampa della lista e stampa su console
 */


/*
PARTE 2
Inserisci la scuola:
"Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
all'INIZIO della linkedList
 */



/*
PARTE 3
Ord
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1024
#define LENRIGA 500

typedef struct Scuola
{
    char nome[DIM];
    char citta[DIM];
    char via[DIM];
    int numAlunni;
    float valutazione;
    struct Scuola *next;
}Scuola;

void stampaLista(Scuola *current);

int main()
{
    Scuola *head = (Scuola *)malloc(sizeof(Scuola));

    FILE *f = fopen("elencoScuole.csv", "r");

    if (f == NULL)
    {
        return -1;
    }
    
    char bin[DIM];
    int aggiunto = 0;

    fgets(bin, LENRIGA, f);

    Scuola *current = head;
    while (fscanf(f, "%s,%s,%s,%d,%f", current->nome, current->citta, current->via, &current->numAlunni, &current->valutazione) != EOF)
    {
        printf("e"); //ricorda ci cancellare
        Scuola *new = (Scuola *)malloc(sizeof(Scuola));
        current->next = new;
        new->next = NULL;
        current = new;
    }
    
    current = head;

    printf("e");
    while (current != NULL) // fatto 2 volte. ?
    {
        printf("nome: %s\ncitta: %s\nvia: %s\nnumAlunni: %d\nvalutazione: %.2f",current->nome, current->citta, current->via, current->numAlunni, current->valutazione);
        current = current->next;
    }

    stampaLista(current); // qua current è al fondo

    current = head;
    Scuola *head1 = (Scuola *)malloc(sizeof(Scuola)); // nome errato
    strcpy(head1->nome, "Istituto Nautico Amerigo Vespucci");
    strcpy(head1->via, "Via del Porto 45");
    strcpy(head1->citta, "Genova");
    head1->numAlunni = 700;
    head1->valutazione = 4.5;

    while (current != NULL)
    {   
    }
    
    while (current != head) // current è uguale a head
    {
        current = current->next;
    }

    head = head1;

    int sca = 0;
    current = head;
    while (sca != 0)
    {
        sca = 1;
 
        Scuola *prossimo = current->next;

        if (current->numAlunni > prossimo->numAlunni)
        {
            Scuola *temp2 = current;
            current = prossimo;
            prossimo = temp2;
            sca = 1;
        }

        current = current->next;       
    }
    
    stampaLista(current);
    return 0;
}

void stampaLista(Scuola *current)
{
    while (current != NULL)
    {
        printf("nome: %s\ncitta: %s\nvia: %s\nnumAlunni: %d\nvalutazione: %.2f",current->nome, current->citta, current->via, current->numAlunni, current->valutazione);
        current = current->next;
    }
}