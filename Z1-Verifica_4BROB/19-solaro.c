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


PARTE 2
Inserisci la scuola:
"Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
all'INIZIO della linkedList


PARTE 3
Ordina la LinkedList in base al numero di studenti in modo crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 1024

typedef struct Scuola
{
    struct Scuola* nextScuola;
    char nomeScuola[LUNG];
    char citta[LUNG];
    char via[LUNG];
    int numeroAlunni;
    float valutazione;

}Scuola;

void stampaLista(Scuola* head);
void liberaLista(Scuola* head);

int main()
{
    /*PARTE 1
    Leggi il file .csv e inserisci i dati dentro una lista
    Crea una funzione per la stampa della lista e stampa su console*/

    Scuola* head=NULL;
    Scuola* previus=NULL;

    FILE* pFile;
    pFile=fopen("elencoScuole.csv", "r");
    if(pFile==NULL)
    {
        perror("errore apertura file");
        return -1;
    }
    else
    {
        char riga[LUNG];
        int i=0;
        while (fgets(riga, LUNG, pFile))
        {
            //printf("%s", riga);
            if(i!=0)
            {
                Scuola* nuovo=(Scuola*)malloc(sizeof(Scuola));
                nuovo->nextScuola=NULL;
                sscanf(riga,"%[^,],%[^,],%[^,],%d,%f", nuovo->nomeScuola, nuovo->citta, nuovo->via, &nuovo->numeroAlunni, &nuovo->valutazione);
                if(previus==NULL)
                    {
                        head=nuovo;
                        printf("Testa creata\n");
                    }
                else
                    previus->nextScuola=nuovo;
                previus=nuovo;
            }
            i++;
        } 
        fclose(pFile);
    }

    printf("presa in input ");
    stampaLista(head);


    /*PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList*/
    Scuola* scuolaInizio=(Scuola*)malloc(sizeof(Scuola));
    strcpy(scuolaInizio->nomeScuola, "Istituto Nautico Amerigo Vespucci");
    strcpy(scuolaInizio->citta, "Genova");
    strcpy(scuolaInizio->via, "Via del Porto 45");
    scuolaInizio->numeroAlunni=700;
    scuolaInizio->valutazione=4.5;
    
    scuolaInizio->nextScuola=head;
    head=scuolaInizio;

    stampaLista(head);

    /*PARTE 3
    Ordina la LinkedList in base al numero di studenti in modo crescente*/

    Scuola* current;
    bool ordinata=false;
    while (!ordinata)
    {
        current=head;
        ordinata=true;
        while (current!=NULL&&current->nextScuola!=NULL)
        {
            if(current->numeroAlunni > current->nextScuola->numeroAlunni)
            {
                ordinata=false;
                //scambia
                Scuola appoggio;
                strcpy(appoggio.nomeScuola, current->nomeScuola);
                strcpy(current->nomeScuola, current->nextScuola->nomeScuola);
                strcpy(current->nextScuola->nomeScuola, appoggio.nomeScuola);
                
                strcpy(appoggio.citta, current->citta);
                strcpy(current->citta, current->nextScuola->citta);
                strcpy(current->nextScuola->citta, appoggio.citta );

                strcpy(appoggio.via, current->via);
                strcpy(current->via, current->nextScuola->via);
                strcpy(current->nextScuola->via, appoggio.via);

                appoggio.numeroAlunni=current->numeroAlunni;
                current->numeroAlunni=current->nextScuola->numeroAlunni;
                current->nextScuola->numeroAlunni=appoggio.numeroAlunni;

                appoggio.valutazione=current->valutazione;
                current->valutazione=current->nextScuola->valutazione;
                current->nextScuola->valutazione=appoggio.valutazione;
            }
            current=current->nextScuola;
        }
        
    }

    stampaLista(head);

    liberaLista(head);
    

    return 0;
}

void stampaLista(Scuola* head)
{
    Scuola* current=head;
    printf("LISTA:\n");
    while (current!=NULL)
    {
        printf("Nome: %s, citta: %s, via; %s, numero alunni: %d, valutazione: %.2f\n", current->nomeScuola, current->citta, current->via, current->numeroAlunni, current->valutazione);
        current=current->nextScuola;
    }
    printf("\n");    
}

void liberaLista(Scuola* head)
{
    Scuola* current=head;
    while (current!=NULL)
    {
        Scuola* libera;
        libera=current;
        current=current->nextScuola;
        free(libera);
    }
}