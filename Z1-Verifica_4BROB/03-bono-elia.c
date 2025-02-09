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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 30

typedef struct Nodo
{
    char nome[DIM];
    char citta[DIM];
    char via[DIM];
    int nAlunni;
    float valutazione;
    struct Nodo *next;
}Nodo;


int main(){

    char nomeTemporale[DIM],cittaTemporale[DIM],viaTemporale[DIM];


    //apro il file
    FILE* f=fopen("elencoScuole.csv", "r");
    if(f==NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }
    
    //creo la testa
    Nodo* inizio=(Nodo*)malloc(sizeof(Nodo)); //err
    
    //salto la prima riga perchè non serve
    char line[200];
    fgets(line, sizeof(line),f);

    while(fgets(line, sizeof(line), f))
    {
        Nodo* nuovoNodo=(Nodo*)malloc(sizeof(Nodo));
        if (!nuovoNodo)
        {
            printf("Errore di allocazione memoria\n");
            return 1;
        }
        //prendo i valori fino a fine riga 
        sscanf(line, "%49[^,],%49[^,],%49[^,],%d,%f", &nuovoNodo->nome, nuovoNodo->citta, nuovoNodo->via, &nuovoNodo->nAlunni, &nuovoNodo->valutazione);
        nuovoNodo->next=NULL;
    
        // Inserimento alla fine della lista
        if(inizio==NULL)
        {
            inizio=nuovoNodo;
        }
        else
        {
            Nodo* corrente=inizio;
            while (corrente->next!=NULL)
            {
                corrente=corrente->next;
            }
            corrente->next=nuovoNodo;
        }

    }

    
    printf("Lista delle scuole:\n");
    Nodo* corrente=inizio;
    while(corrente!=NULL)
    {
        printf("Nome: %s, Città: %s, Via: %s, Numero alunni: %d, Valutazione: %f\n",corrente->nome, corrente->citta, corrente->via, corrente->nAlunni, corrente->valutazione);
        corrente=corrente->next;
    }

    Nodo* nuovoNodo=(Nodo*)malloc(sizeof(Nodo));
    if(!nuovoNodo)
    {
        printf("Errore.\n");
        return 1;
    }
    strcpy(nuovoNodo->nome,"Istituto Nautico Amerigo Vespucci");
    strcpy(nuovoNodo->citta, "Genova");
    strcpy(nuovoNodo->via,"Via del Porto 45");
    nuovoNodo->nAlunni=700;
    nuovoNodo->valutazione=4,5;

    if(inizio==NULL)
    {
    inizio=nuovoNodo;
    }
    else
    {
        corrente=inizio;
        while (corrente->next!=NULL)
        {
            corrente=corrente->next;
        }
        corrente->next=nuovoNodo;
    }


    printf("\nLista ordinata in ordine crescente in base al numero di studenti:\n");
    if(inizio!=NULL)
    {
        Nodo* i=inizio;
        Nodo* j=NULL;
        while(i!=NULL)
        {
            j=i->next;
            while(j!=NULL)
            {
                if(i->nAlunni>j->nAlunni)
                {
    
                    //copio i dati di i in temp
                    strcpy(nomeTemporale,i->nome);
                    strcpy(cittaTemporale,i->citta);
                    strcpy(viaTemporale,i->via);
                    int nAlunniTemp=i->nAlunni;
                    float valutazioneTemp=i->valutazione;
    
                    //copio i dati di j in i
                    strcpy(i->nome,j->nome);
                    strcpy(i->citta,j->citta);
                    strcpy(i->via,j->via);
                    i->nAlunni=j->nAlunni;
                    i->valutazione=j->valutazione;
    
                    //copio i dati di temp in j
                    strcpy(j->nome,nomeTemporale);
                    strcpy(j->citta,cittaTemporale);
                    strcpy(j->via,viaTemporale);
                    j->nAlunni=nAlunniTemp;
                    j->valutazione=valutazioneTemp;
                }
                j=j->next;
            }
            i=i->next;
        }
    }

    printf("Lista delle scuole:\n");
    corrente=inizio;
    while(corrente!=NULL)
    {
        printf("Nome: %s, Città: %s, Via: %s, Numero alunni: %d, Valutazione: %f\n",corrente->nome, corrente->citta, corrente->via, corrente->nAlunni, corrente->valutazione);
        corrente=corrente->next;
    }

    
    fclose(f);

    return 0;
}





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
