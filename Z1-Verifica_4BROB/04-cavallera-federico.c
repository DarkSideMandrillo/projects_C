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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTRING 200

//main stuct
typedef struct Scuole
{
    char nome[MAXSTRING];
    char citta[MAXSTRING];
    char via[MAXSTRING];
    int nAlunni;
    float valutazioneScuola;
    struct Scuole *next;
}Scuole;

void *scrivi(Scuole* Head);
Scuole* ordinaScuola(Scuole *head);

int main(){
    Scuole *head = (Scuole*)malloc(sizeof(Scuole)); //doppio
    FILE *f = fopen("elencoScuole.csv", "r");

    if(f == NULL){
        printf("File non aperto correttamente!\n");
        return -1;
    } else {
        printf("File aperto correttamente\n");
    }

    char bin[1024];
    fgets(bin, sizeof(bin), f);

    Scuole *old = head;
    while (fscanf(f, "%199[^,],%199[^,],%[^,],%d,%f", old->nome, old->citta, old->via, &old->nAlunni, &old->valutazioneScuola) != EOF) {
        Scuole *new = (Scuole*)malloc(sizeof(Scuole));
        if (new == NULL) {
            printf("Errore di allocazione memoria.\n");
            break;
        }
        old->next = new;
        new->next = NULL;
        old = new;    
    }    

    head = ordinaScuola(head);
    scrivi(head);

    
    //nuovo nodo
    Scuole *newNode = (Scuole*)malloc(sizeof(Scuole));

    strcpy(newNode->nome,"Istituto Nautico Amerigo Vespucci");
    strcpy(newNode->via,"Via del Porto 45");
    strcpy(newNode->citta,"Genova");

    newNode->nAlunni = 700;
    newNode->valutazioneScuola = 4.5;

    head->next = newNode;
    head = newNode;



    temp = head;
    while (temp != NULL)
    {
        Scuole *next = temp->next;
        free(temp);
        temp = next;
    }

    fclose(f);

    return 0;   
}

Scuole* ordinaScuola(Scuole *head) {
    if (head == NULL) return NULL;

    bool swapped;
    do {
        swapped = false;
        Scuole *prev = NULL, *curr = head, *next = head->next;

        while (next != NULL) {
            if (curr->nAlunni > next->nAlunni) {
                swapped = true;
                curr->next = next->next;
                next->next = curr;

                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }

                prev = next;
                next = curr->next;
            } else {
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
    } while (swapped);

    return head;
}
void *scrivi(Scuole* Head){
    Scuole *temp = Head;
    while (temp != NULL)
    {
        printf("%s,%s,%s,%d,%f", temp->nome, temp->citta, temp->via, temp->nAlunni, temp->valutazioneScuola);
        temp = temp->next;
    }
}