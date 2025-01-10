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
//mancano le lib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define DIM_RIGA 100
# define DIM_STRINGA 30

typedef struct Node // CREAZIONE DEL NODO CON I DATI RICHIESTI
{
    char nomeScuola[DIM_STRINGA];
    char Citta[DIM_STRINGA];
    char Via[DIM_STRINGA];
    int NumeroAlunni;
    float ValutazioneScuola;

    struct Node *next;
}Node;

int main()
{

    FILE *file = fopen("elencoScuole.csv", "r"); // APERTURA DEL FILE IN LETTURA
    char buffer[DIM_RIGA];

    Node *head = NULL, *tempAttuale = NULL, *tempPrecedente = NULL, *temp;

    fgets(buffer, DIM_RIGA, file); // SALTA LA PRIMA RIGA 

    while(fgets(buffer[DIM_RIGA]) != 0)
    {
        tempAttuale = (Node*)malloc(sizeof(Node));

         token = strtok(NULL, ",");
         strcpy(tempAttuale->nomeScuola, token);

         token = strtok(NULL, ",");
         strcpy(tempAttuale->Citta, token);

         token = strtok(NULL, ",");
         strcpy(tempAttuale->Via, token);

         token = strtok(buffer, ",");
         tempAttuale-> = atoi(token);

         token = strtok(buffer, ",");
         tempAttuale-> = atof(token);

         tempAttuale->next = NULL;

         if(head == NULL) // SE NON ESISTE IL HEAD LO CREA
         {
             head = tempAttuale;
         }
         else // ALTRIMENTI CREA UN NUOVO NODE
         {
             tempPrecedente->next = tempAttuale;
         }
         tempPrecedente = tempAttuale;
    }
    fclose(file);

    print("Tutte le scuole: \n");
    temp = head;
    while(temp != NULL) // STAMPA I VALORI DI OGNI NODE
    {
        printf("nome scuola: %s", temp->nomeScuola);
        printf("citta: %s ", temp->Citta);
        printf("via: %s", temp->Via);
        printf("numero alunni: %d", temp->NumeroAlunni);
        printf("valutazione scuola: %f", temp->ValutazioneScuola);

        temp = temp->next;
    }


/*
PARTE 2
Inserisci la scuola:
"Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
all'INIZIO della linkedList
 */

    void inserisciNodo(Nodo* head) 
    {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo)); // CREA UN NUOVO NODO
    nuovoNodo->next = *head;
    *head = nuovoNodo; // E LO INSERISCE COME HEAD
    }

/*
PARTE 3
Ordina la LinkedList in base al numero di studenti in modo crescente
 */

*temp1 = head, *temp2;
for(temp1 = head; temp1 != NULL; temp1 = temp1->next) {
    for(temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
        if(temp1->NumeroAlunni > temp2->NumeroAlunni) {
            int tempNalunni = temp1->NumeroAlunni;
            temp1->NumeroAlunni = temp2->NumeroAlunni;
            temp2->NumeroAlunni = tempQuantita;
        }
    }
}
