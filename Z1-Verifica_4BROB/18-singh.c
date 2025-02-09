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
Ordina la LinkedList in base al numero di studenti in modo crescente
 */

/*PARTE 1
Leggi il file .csv e inserisci i dati dentro una lista
Crea una funzione per la stampa della lista e stampa su console
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 1000
typedef struct Scuole
{
    char* name;
    char* citta;
    char* via;
    int alunni;
    float valutazione;

    struct Scuole *next;
}Scuole;

void print(Scuole* head);
void freeMem(Scuole *head);
Scuole* inizioScuola(Scuole* head);
void ordina(Scuole* head);

int main(){
    Scuole *head;
    Scuole *current;
    Scuole *prev=NULL;
    char nomeFile[] = {"elencoScuole.csv"};
    FILE *fp;

    fp = fopen(nomeFile, "r");
    int file;
    int count = 0;

    while (file != EOF)
    {
        current = (Scuole*)malloc(sizeof(Scuole));
        //current->name = (char*)malloc(sizeof(char)*DIM);
        //current->citta = (char*)malloc(sizeof(char)*DIM);
        // manca - fgets(line, sizeof(line), file); //Salta l'intestazione

        file = fscanf(fp, "%s,%s,%s,%d,%f", current->name, current->citta, current->via, &current->alunni, &current->valutazione);
        if (count == 0)
        {
            head=current;
            head->next = NULL;
        }
        else{
            prev->next = current;
            current->next = NULL;
        }
    }

    head = inizioScuola(head);
    print(head);
    freeMem(head);

    return 0;
}

void print(Scuole *head)
{
    Scuole* current = head;
    while (current != NULL)
    {
        printf("%s,%s,%s,%d,%f", current->name, current->citta, current->via, current->alunni, current->valutazione);

        current = current->next;
    }
    
}

void freeMem(Scuole *head)
{
    Scuole* current = head;
    Scuole *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
}

// "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
Scuole *inizioScuola(Scuole *head)
{
    Scuole* sorted; // la malloc devi farela qui
    sorted->name = (char*)malloc(sizeof(char)*DIM); 
    sorted->name = "Istituto Nautico Amerigo Vespucci";
    sorted->citta = "Genova";
    sorted->via = "Via del Porto 45";
    sorted->alunni = 700;
    sorted->valutazione = 4.5;
    // devi assegnare alla next la testa
    return sorted;
}

void ordina(Scuole *head)
{
    Scuole* sorted;
    Scuole *current = head;

    while (current != NULL) // current->next
    {
        if (current->alunni > current->next->alunni)
        {
            Scuole *temp = current; //devi usare il temp per lo swap
            strcpy(current->citta, current->next->citta);
            strcpy(current->name, current->next->name);
            strcpy(current->via, current->next->via);
            current->alunni = current->next->alunni;
            current->valutazione = current->next->valutazione;

            strcpy(current->next->citta, temp->citta);
        }
        
    }
    
}
