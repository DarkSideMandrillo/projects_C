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

//lista a puntatore
typedef struct Node{
    char nome[50];
    char citta[50]; 
    char via[50];
    int numAlunni;
    float valutazione; 

    Node *next;
}Node;

//dichiarazione delle funzioni
Node* readCSV (const char *filename);
void stampaList (Node *head);
void addNodo (Node *nodo);
void sort (Node *head);

//main
int main(){

    Node *head = NULL;

    readCVS("elencoScuole.cvs"); // ritorna qualcosa

    stampaList(&head); //err

    addNodo (&head);

    return 0;
}

//definizione delle funzioni

//Funzione per leggere il file CSV e caricare i dati nella lista
Node* readCSV(const char *filename) {
    // Apri il file in modalità lettura
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Errore nell'apertura del file.\n");
        return NULL;
    }

    Node *head = NULL;
    char line[250];

    fgets(line, sizeof(line), file); //Salta l'intestazione

    //Ciclo per leggere ogni riga 
    while (fgets(line, sizeof(line), file)) // meglio con EOF
    {
        char nome[50], citta[50], via[50];
        int numAlunni;
        float valutazione;

        if (sscanf(line, "%s,%s,%s,%d,%f", nome, citta, via, &numAlunni, &valutazione) == 5) 
        { //"%49[^,],%49[^,],%49[^,],%d,%f"
            Node *nuovoNodo = (Node*)malloc(sizeof(Node));
            
            head = nuovoNodo(head, nome, citta, via, numAlunni, valutazione); // non e una func
        } else {
            printf("Errore nella lettura della riga");
        }
    }

    fclose(file);
    return head;  
}


//Stampa la lista a terminale
void stampaList(Node *head) 
{
    Node *temp = head;

    //Scorre il nodo
    while (temp != NULL) 
    {
        printf("Nome: %s, Città: %s, Via: %s, Numero Alunni: %d, Valutazione: %.1f\n",temp->nome, temp->citta, temp->via, temp->numAlunni, temp->valutazione);
        temp = temp->next;
    }
}

//Permette di aggiungere un nodo all'inizio della lista
void addNodo(Node *head) {
    Node *nuovoNodo = (Node*)malloc(sizeof(Node));

    //se non riesce ad allocare
    if (nuovoNodo == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return;
    }

    //Assgna i valori al nodo
    strcpy(nuovoNodo->nome, "Istituto Nautico Amerigo Vespucci");
    strcpy(nuovoNodo->citta, "Genova");
    strcpy(nuovoNodo->via, "Via del Porto 45");
    nuovoNodo->numAlunni = 700;
    nuovoNodo->valutazione = 4.5;

    nuovoNodo->next= head;

    // Aggiorna la testa della lista
    head = nuovoNodo;
}

//Ordina la lista in modo crescente
void sort (Node *head)
{

}