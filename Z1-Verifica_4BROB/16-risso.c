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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 256 //!! Non utilizzata nel codice

typedef struct Scuole //!! Avevi scritto solo typedef struct
{
    char nomeScuola[256];
    char citta[256];
    char via[256];
    int numeroAlunni;
    float valutazioneScuola;
    struct Scuole* next;
   
}Scuole;

//!! Mancano le dichiarazioni delle funzioni all'inizio
void stampaLista(Scuole *attuale, Scuole *head );

void main()
{
    //!! non ti servono queste variabili, hai già la struttura
    //!! facendo così, stai creando enormi conflitti di nomi
    // char nomeScuola[256]; 
    // char citta[256];
    // char via[256];
    // int numeroAlunni;
    // float valutazioneScuola;
    char linea[256];

    Scuole *attuale;
    Scuole *passato;
    Scuole *head = NULL; //!! correzione



    FILE *fp;
    fp=fopen("elencoScuole.csv", "r");
    if (fp==NULL)
    {
        printf(" errore nell'apertura");
    }

    fgets(linea, sizeof(linea), fp); //!!da commentare

    while(fgets(linea, sizeof(linea), fp)!=NULL)
    {   
        //!! creo prima il nodo
        attuale=(Scuole*)malloc(sizeof(Scuole));

        //!!prima il buffer, poi i dati
        //sscanf(linea,"%s, %s, %s, %d, %f", nomeScuola, citta,via, &numeroAlunni, &valutazioneScuola);
        sscanf(linea,"%255[^,],%255[^,],%255[^,], %d, %f", attuale->nomeScuola, attuale->citta,attuale->via, &attuale->numeroAlunni, &attuale->valutazioneScuola);

        //!! inserendo direttamente con sscanf non abbiamo bisogno di fare delle strcpy
        // strcpy(attuale->nomeScuola,nomeScuola);
        // strcpy(attuale->citta,citta);
        // strcpy(attuale->via,via);
        // attuale->numeroAlunni=numeroAlunni;
        // attuale->valutazioneScuola=valutazioneScuola;
        attuale->next=NULL;

        if (head==NULL)
        {
            head=attuale;
            //attuale=head->next; //!! head-> next punta ad un NULL. Non serve
        }
        else{ //errore
            //attuale=passato; //!! al contrario
            //passato=passato->next; // no
            passato->next = attuale; //!! correzione
            
        }
        passato = attuale; //!! correzione
    }

    //stampaLista(&attuale, &head); //!! errore per mancanza di definizione
    printf("\nLISTA CARICATA:\n");
    stampaLista(attuale, head);
    /*
    PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList
    */

   //!! devi creare un nodo per inserire i dati e poi aggiungerlo alla lista concatenata
    Scuole *nuovo = (Scuole*) malloc(sizeof(Scuole)); //!! creazione del nodo da aggiungere
   // Scuole *temp; //!! non serve
    strcpy(nuovo->nomeScuola,"Istituto Nautico Amerigo Vespucci");
    strcpy(nuovo->citta,"Genova");
    strcpy(nuovo->via,"Via del Porto 45");
    nuovo->numeroAlunni=700;
    nuovo->valutazioneScuola=4.5;
    nuovo->next=NULL;

    nuovo->next = head; //!! il nuovo nodo->next punterà alla testa(precedente)
    head = nuovo; //!! Ora il nuovo nodo diventa la nuova testa

    printf("\nLISTA CON NUOVO NODO IN TESTA:\n");
    stampaLista(attuale, head);

    // head->next=temp; // errore
    // head=nuovo; 
    // head->next=temp;

    /*
    PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente
    */
   //!! ATTENZIONE, non corretto. correggilo in autonomia
   //!! la logica è corretta
   Scuole *prima; //!! se usi come nome prima, allora fai che sia il precedente nodo e non il successivo, altrimenti cambia nome alla variabile
   bool scambio = true;
   
   while(scambio == true) {
       attuale = head; //
       scambio = false;
       while(attuale->next != NULL) 
       {
        prima=attuale->next;
           if(attuale->numeroAlunni > prima->numeroAlunni) 
           {    //!! non scambiare solo il numero, ma tutti i dati all'interno della lista
               int temp = attuale->numeroAlunni;
               attuale->numeroAlunni =prima->numeroAlunni;
               prima->numeroAlunni = temp;
               scambio = true; 
           }
           attuale = prima;
       }
   }

    printf("\nLISTA ORDINATA:\n");
   stampaLista(attuale, head);

}

void stampaLista(Scuole *attuale, Scuole *head ) // basta solo l'head. oppure attuale lo si può definire nella func
{
    attuale=head;
    while(attuale->next!=NULL)
    {   //!! migliorato la stampa
        printf("nome: %s,\ncitta:  %s,\nvia:  %s,\nnumero alunni:  %d,\nvalutazione: %f\n\n", attuale->nomeScuola, attuale->citta,attuale->via, attuale->numeroAlunni, attuale->valutazioneScuola);
        attuale=attuale->next;
    }

}






