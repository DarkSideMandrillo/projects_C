/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |      */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_STRINGA 50
#define DIM_BUFFER 100
typedef struct Node
{
    char nomeScuola[DIM_STRINGA];
    char citta[DIM_STRINGA];
    char via[DIM_STRINGA];
    int numeroAlunni;
    float valutazioneScuola;

    struct Node *next;
}Node;

void stampaLista(Node *head);
void inserisciScuolaInLista(Node **head);
void ordinaCrescentePerStudenti(Node *head);
int main()
{
    FILE *file = fopen("elencoScuole.csv", "r");
    char buffer[DIM_BUFFER];
    fgets(buffer, DIM_BUFFER, file); //!! commento mancante
    char *token;

    Node *tempAttuale, *tempPrecedente, *head = NULL, *temp;
    while(fgets(buffer, DIM_BUFFER, file) != NULL)
    {
        tempAttuale = (Node*)malloc(sizeof(Node));
        if(tempAttuale == NULL)
        {
            perror("Errore nell'allocazione della memoria. \n");
        }
        tempAttuale->next = NULL;

        // Assegnazione di tutti i campi della struttura ai valori contenuti nel file
        token = strtok(buffer, ",");
        strcpy(tempAttuale->nomeScuola, token);

        token = strtok(NULL, ",");
        strcpy(tempAttuale->citta, token);

        token = strtok(NULL, ",");
        strcpy(tempAttuale->via, token);

        token = strtok(NULL, ",");
        tempAttuale->numeroAlunni = atoi(token);

        token = strtok(NULL, ",");
        tempAttuale->valutazioneScuola = atof(token);
        
        if(head == NULL)
        {
            head = tempAttuale;
        }
        else
        {
            tempPrecedente->next = tempAttuale;
        }
        tempPrecedente = tempAttuale;
    }
    stampaLista(head);
    ordinaCrescentePerStudenti(head);
    printf("\n\n Scuole dopo l'ordinamento in ordine crescente di studenti: \n");
    stampaLista(head);
    inserisciScuolaInLista(&head);
    printf("\n\n Scuole dopo l'inserimento della scuola all'inizio: \n");
    stampaLista(head);
}
void stampaLista(Node *head) // PROCEDURA PER STAMPARE TUTTI I CAMPI DI OGNI NODO DI UNA LINKED LIST
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("Nome scuola: %s\n", temp->nomeScuola); //!! mancano \n
        printf(", citta' scuola: %s\n", temp->citta);
        printf(", via: %s\n", temp->via);
        printf(", numero alunni: %d\n", temp->numeroAlunni);
        printf(", valutazione scuola: %f\n", temp->valutazioneScuola);
        printf("\n");
        temp = temp->next;
    }
}
void ordinaCrescentePerStudenti(Node *head) // PROCEDURA PER ORDINARE UNA LINKED LIST IN BASE AL NUMERO DI STUDENTI IN MODO CRESCENTE
{
    Node *i, *j; //!! i e j non sono buoni nomi di variabili
    float valutazioneTemp;
    int nAlunniTemp;
    char viaTemp[DIM_STRINGA], cittaTemp[DIM_STRINGA], nomeTemp[DIM_STRINGA];

    for(i = head; i != NULL; i = i->next) //difficile, ma qua si capisce e fatto bene
    {
        for(j = i->next; j != NULL; j = j->next) //!! una un while che non ti sbagli ed è più leggibile
        {
            if(i->numeroAlunni > j->numeroAlunni)
            {
                // Scambio tutti i campi della lista tra i nodi
                strcpy(nomeTemp, i->nomeScuola);
                strcpy(i->nomeScuola, j->nomeScuola);
                strcpy(j->nomeScuola, nomeTemp);

                strcpy(cittaTemp, i->citta);
                strcpy(i->citta, j->citta);
                strcpy(j->citta, cittaTemp);

                strcpy(viaTemp, i->citta);
                strcpy(i->citta, j->citta);
                strcpy(j->citta, viaTemp);

                nAlunniTemp = i->numeroAlunni;
                i->numeroAlunni = j->numeroAlunni;
                j->numeroAlunni = nAlunniTemp;

                valutazioneTemp = i->valutazioneScuola;
                i->valutazioneScuola = j->valutazioneScuola;
                j->valutazioneScuola = valutazioneTemp;
            }
        }
    }
}
void inserisciScuolaInLista(Node **head) // PROCEDURA PER INSERIRE LA SCUOLA CON I DATI: "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5 ALL'INIZIO DELLA LINKED LIST
{
    Node *nuovaScuola = (Node*)malloc(sizeof(Node));
    if (nuovaScuola == NULL)
    {
        perror("Errore nell'allocazione della memoria. \n");
    }
    //!! hai già i dati, perchè li metti in un buffer?
    char buffer[] = "Istituto Nautico Amerigo Vespucci,Genova,Via del Porto 45,700,4.5";
    
    char *token = strtok(buffer, ",");
    strcpy(nuovaScuola->nomeScuola, token);

    token = strtok(NULL, ",");
    strcpy(nuovaScuola->citta, token);

    token = strtok(NULL, ",");
    strcpy(nuovaScuola->via, token);

    token = strtok(NULL, ",");
    nuovaScuola->numeroAlunni = atoi(token);

    token = strtok(NULL, ",");
    nuovaScuola->valutazioneScuola = atof(token);

    nuovaScuola->next = head; 
    head = nuovaScuola;       
}

