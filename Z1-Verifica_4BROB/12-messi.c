/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |      

CleanCode = Commenti nel codice, Nome variabili corrette, codice non ripetuto, logica ottimizzata
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define DIM 100

typedef struct Scuola
{
    char nomeScuola[DIM];
    char citta[DIM];
    char via[DIM];
    int numeroAlunni;
    float valutazioneScuola;
    struct Scuola* nextScuola;
}Scuola;

int main()
{
    /*
    PARTE 1
    Leggi il file .csv e inserisci i dati dentro una lista
    Crea una funzione per la stampa della lista e stampa su console
    */

    Scuola* head = NULL;  //creo il nodo testa e gli assegno valore null
    Scuola* precedente = NULL; //creo il nodo precedente e gli assegno il valore null

    //APRO IL FILE
    FILE* fp;
    fp=fopen("elencoScuole.csv", "r");
    if(fp==NULL)
    {
        perror("Errore durante l'apertura del file");
        return -1;
    }
    else
    {
        Scuola* attuale = (Scuola*)malloc(sizeof(Scuola)); // la malloc la devi fare per ogni nodo
        attuale->nextScuola=NULL;
        // il primo è da saltare
        while (fscanf(fp, "%99[^,], %[^,], %[^,], %d, %f", attuale->nomeScuola, attuale->citta, attuale->via, &attuale->numeroAlunni, &attuale->valutazioneScuola)!=EOF) //piccolo err
        {
            if(precedente==NULL)
            {
                head = attuale;
            }
            else
            {
                precedente->nextScuola=attuale;
            }
            precedente=attuale;
        }
        fclose(fp);
    }


    //STAMPO LA LISTA
    Scuola* attuale = head;
    while (attuale!=NULL)
    {
        printf("\n%s \n%s \n%s \n%d \n%.2f", attuale->nomeScuola, attuale->citta, attuale->via, attuale->numeroAlunni, attuale->valutazioneScuola);
        attuale=attuale->nextScuola;
    }




    /*
    PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList
    */

    attuale=head;
    while (attuale->nextScuola!=NULL) // inizio non fine
    {
            attuale=attuale->nextScuola;
    }
    
    Scuola* nuovaScuola = (Scuola*)malloc(sizeof(Scuola));
    //assegno alla nuova scuola i valori
    strcpy(nuovaScuola->nomeScuola,"Istituto Nautico Amerigo Vespucci");
    strcpy(nuovaScuola->citta,"Genova");
    strcpy(nuovaScuola->via, "Via del porto 45");
    nuovaScuola->numeroAlunni=700;
    nuovaScuola->valutazioneScuola=4.5;
    nuovaScuola->nextScuola=NULL;

    attuale->nextScuola=nuovaScuola;

    attuale=head;
    while (attuale!=NULL)
    {
        printf("\n%s \n%s \n%s \n%d \n%.2f", attuale->nomeScuola, attuale->citta, attuale->via, attuale->numeroAlunni, attuale->valutazioneScuola);
        attuale=attuale->nextScuola;
    }


    /*
    PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente
    */

    attuale=head;
    bool ordinato=false;
    while (!ordinato)
    {
        attuale=head;
        ordinato=true;
        while (attuale!=NULL&&attuale->nextScuola!=NULL)
        {
            if (attuale->numeroAlunni>attuale->nextScuola->numeroAlunni)
            {
                Scuola appoggio; // non dentro il ciclo

                strcpy(appoggio.nomeScuola, attuale->nomeScuola);
                strcpy(attuale->nomeScuola, attuale->nextScuola->nomeScuola);
                strcpy(attuale->nextScuola->nomeScuola, appoggio.nomeScuola);

                strcpy(appoggio.citta, attuale->citta);
                strcpy(attuale->citta, attuale->nextScuola->citta);
                strcpy(attuale->nextScuola->citta, appoggio.citta);

                strcpy(appoggio.via, attuale->via);
                strcpy(attuale->via, attuale->nextScuola->via);
                strcpy(attuale->nextScuola->via, appoggio.via);

                appoggio.numeroAlunni=attuale->numeroAlunni;
                attuale->numeroAlunni = attuale->nextScuola->numeroAlunni;
                attuale->nextScuola->numeroAlunni=appoggio.numeroAlunni;

                appoggio.valutazioneScuola=attuale->valutazioneScuola;
                attuale->valutazioneScuola = attuale->nextScuola->valutazioneScuola;
                attuale->nextScuola->valutazioneScuola=appoggio.valutazioneScuola;

                ordinato=false;
            }
            attuale=attuale->nextScuola;
        }
    }

    attuale=head;
    while (attuale!=NULL)
    {
        printf("\n%s \n%s \n%s \n%d \n%.2f", attuale->nomeScuola, attuale->citta, attuale->via, attuale->numeroAlunni, attuale->valutazioneScuola);
        attuale=attuale->nextScuola;
    }

}