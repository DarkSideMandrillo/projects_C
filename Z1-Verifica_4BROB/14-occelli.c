/*Crea una cartella nuova sul desktop
Apri la cartella con VS Code
Copia il file .csv dentro la cartella
Crea un nuovo file main.c e incolla i seguente testo:*/
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

#define MAX 11

typedef struct Node
{
    char nome[MAX];
    char scuola[MAX];
    char citta[MAX];
    char via[MAX];
    int num_alunni;
    float valutazione;

    struct Node*prossimo;
}Node;

Node* leggiFile(char nomeFile[]);
void stampa(Node*head);
void ordinamento(Node*head);

int main()
{
    //ASSEGNA CONTENUTO LETTO DAL FILE
    Node* head=leggiFile("elencoScuole.csv");

    //STAMPA LISTA
    stampa(head);

    //ORDINAMENTO
    ordinamento(head);

    //STAMPA ORDINAMENTO
    stampa(head);

    Node*temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->prossimo;
        free(temp);
    }

    return 0;
}

//PARTE 1
Node* leggiFile(char nomeFile[])
{
    FILE * fl = fopen(nomeFile, "r");
    if(nomeFile==NULL)
    {
        printf("Errore durante l'apertura del file\n");
        return -1;
    }
        Node*head=NULL;
        Node*temp=NULL; //scanf
        while(fprintf(fl,"%s, %s %s %s %i %f", temp->nome, temp->scuola, temp->citta, temp->via, &temp->num_alunni, &temp->valutazione)!=EOF)
        {
            Node*nuovo=(Node*)malloc(MAX * sizeof(Node));// non MAX
            nuovo=temp;
            nuovo->prossimo=NULL;
            if(head==NULL)
            {
                head=nuovo;
            }
            else
            {
                Node*corrente=head; // strutturato così è piu lungo
                while(corrente->prossimo!=NULL)
                {
                    corrente=corrente->prossimo;  
                }
                corrente->prossimo=corrente; // corrente->prossimo = nuovo
            }
            fclose(fl);
            return head;
    }
}

void stampa(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        printf("Nome: %s - Scuola: %s - Citta': %s - Via: %s - Numero alunni: %i - Valutazione: %2.f", temp->nome, temp->scuola, temp->citta, temp->via, temp->num_alunni, temp->valutazione);
        temp=temp->prossimo;
    }
}

//PARTE 2


//PARTE 3
void ordinamento(Node*head)
{
    if(head==NULL)
    {
        return 1;
    }
    Node* i=head;
    while(i!=NULL)
    {
        Node*min=i;
        Node* j=i->prossimo;
        while(j!=NULL)
        {
            if(j->num_alunni<min->num_alunni)
            {
                min=j;
            }
            j=j->prossimo;
            if(min!=i)
            {
                int temp=i->num_alunni;
                i->num_alunni=min->num_alunni;
                min->num_alunni=temp;
            }
            i=i->prossimo;
        }
    }
}
