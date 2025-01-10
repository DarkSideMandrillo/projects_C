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

#define DIM 50  //Macro per la dimensione

//Creazione struttura
typedef struct elencoscuole
{
    char nomeScuola[DIM];
    char citta[DIM];
    char via[DIM];
    int numAlunni;
    float valutazione;
    struct elencoscuole* next;
    
}elencoscuole;


int main()
{

    //PARTE 1 
    FILE* file = fopen("elencoScuole.csv","r");
    if(file == NULL)
    {
        printf("Errore durante l'apertura del fiile");
        return 1; //retur di 1 perhcè cosi so che ho errori        
    }

    elencoscuole* head = NULL;
    elencoscuole* precente = NULL;

    //buffer per la lettura
    char riga[256];

        //Leggo la riga 
        fgets(riga,sizeof(riga),file);

        //Scorro tutto il file e leggo tutte le righe
        while (fgets(riga,sizeof(riga),file))
        {
            //Creazione del nodo tramite la malloc per contenere le info del file
            elencoscuole* nuovoNodo = (elencoscuole*)malloc(sizeof(elencoscuole));

            //Utilizzo della strtok per estrarre le info dal file

            //Per il nome
            char* token = strtok(riga,",");
            strcpy(nuovoNodo->nomeScuola,token);

            //per citta
            token =strtok(NULL,",");
            strcpy(nuovoNodo->citta,token);

            //Per via
            token =strtok(NULL,",");
            strcpy(nuovoNodo->via,token);
            
            //Per numeroalunni
            token =strtok(NULL,",");
            nuovoNodo->numAlunni = atoi(token);

             //Per valutazioni
            token =strtok(NULL,",");
            nuovoNodo->valutazione = atof(token);

            //Passo alla riga sucessiva
            nuovoNodo->next= nuovoNodo;
            
            
            
        }
        fclose(file);

        printf("Dati della lista");
        elencoscuole* temp = head;  //Creo variabile temper non cancellare il nodo head
        while (temp != NULL)
        {
            printf("nomescuola: %f, citta: %f, via: %f, numAlunni: %d, valutazione %f",temp->nomeScuola, temp->citta, temp->via,  temp->numAlunni,  &temp->valutazione);
            temp=temp->next;
        }


        //PARTE 2
        //aggiungo il nodo
         elencoscuole* nodoAggiunto = (elencoscuole*)malloc(sizeof(elencoscuole));
         strcpy(nodoAggiunto->nomeScuola,"Istituto Nautico Amerigo Vespucci");
         strcpy(nodoAggiunto->citta,"Genova");
         strcpy(nodoAggiunto->via,"Via del Porto 45");
        nodoAggiunto->numAlunni = 700;
        nodoAggiunto->valutazione = 4.5;


        //Libero la memoria
        printf("Libero Memoria");
        temp = head;  //Creo variabile temper non cancellare il nodo head
        while (temp != NULL)
        {
            free(temp);
        }
        

    return 0;

}