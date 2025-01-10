#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |
*/

/*
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

#define DIM 1024

typedef struct Scuola{

    char nomeScuola[DIM];
    char citta[DIM];
    char via[DIM];
    int numeroAlunni;
    float valutazioneScuola;
    struct Scuola* next;

}Scuola;



int main(){

    /*
    PARTE 1
    Leggi il file .csv e inserisci i dati dentro una lista
    Crea una funzione per la stampa della lista e stampa su console
    */

    Scuola* head=NULL;
    

    FILE* f;
    f = fopen("file.csv", "r");
    if(f == NULL)
    {
        printf("Errore durante l'apertura del file ");
        return -1;
    }
    else
    {
        char rigaCSV[DIM];
        int cont=0;

        while (fgets(rigaCSV, DIM, f))
        {
            printf("%s", rigaCSV);
 
        }
        
        fclose(f);

    }

    /*
    PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList
    */
    
    // Scuola* nuovaScuola;
    // nuovaScuola.nomeScuola = "Istituto Nautico Amerigo Vespucci";
    // nuovaScuola->citta = "Genova";
    // nuovaScuola->via = "Via del porto 45";
    // nuovaScuola->numeroAlunni = 700;
    // nuovaScuola->valutazioneScuola = 4.5;



    /*
    PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente
    */

    return 0;
}