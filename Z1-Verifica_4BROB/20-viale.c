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
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

typedef struct Scuola {
    char nome[100];
    char citta[100];
    char via[100];
    int numeroAlunni;
    float valutazione;
    struct Scuola* next;
} Scuola;

Scuola* leggiFileCsv(char* filename);
void stampaLista(Scuola* head);

int main() {
    
    /*
    PARTE 1
    Leggi il file .csv e inserisci i dati dentro una lista
    Crea una funzione per la stampa della lista e stampa su console
    */

    Scuola* head = leggiFileCsv("elencoScuole.csv");
    if (head == NULL) {
        printf("Errore durante la lettura del file\n");
        return 1;
    }

    printf("\nStampa lista delle scuole lette dal file:\n");
    stampaLista(head);

    /*
    PARTE 2
    Inserisci la scuola:
    "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    all'INIZIO della linkedList
    */

    //creazione "Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
    Scuola* nuovaScuola = malloc(sizeof(Scuola));
    strcpy(nuovaScuola->nome, "Istituto Nautico Amerigo Vespucci");
    strcpy(nuovaScuola->citta, "Genova");
    strcpy(nuovaScuola->via, "Via del Porto 45");
    nuovaScuola->numeroAlunni = 700;
    nuovaScuola->valutazione = 4.5;
    nuovaScuola->next = NULL;

    //salva la nuova scuola appena salvata nell head
    nuovaScuola->next = head;
    head = nuovaScuola;
        
    printf("\nStampa lista dopo l'aggiunta della nuova scuola\n");
    stampaLista(head);

    //PARTE 3
    //Ordina la LinkedList in base al numero di studenti in modo crescente

    Scuola* current = head;
    Scuola* next = NULL;
    char tempNome[50];      //creazione variabili secondarie utilizzate poi nello scambio dei dati
    char tempCitta[50];
    char tempVia[50];
    int tempNumeroAlunni;
    float tempValutazione;

    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            if (current->numeroAlunni > next->numeroAlunni) {   //verifica numero alunni minore o maggiore
                
                // Scambio dei valori
                tempNumeroAlunni = current->numeroAlunni;
                strcpy(tempNome, current->nome);
                strcpy(tempCitta, current->citta);
                strcpy(tempVia, current->via);
                tempValutazione = current->valutazione;

                current->numeroAlunni = next->numeroAlunni;
                strcpy(current->nome, next->nome);
                strcpy(current->citta, next->citta);
                strcpy(current->via, next->via);
                current->valutazione = next->valutazione;

                next->numeroAlunni = tempNumeroAlunni;
                strcpy(next->nome, tempNome);
                strcpy(next->citta,tempCitta);
                strcpy(next->via, tempVia);
                next->valutazione = tempValutazione;
            }
            next = next->next;
        }
        current = current->next;
    }

    printf("\nStampa la lista dopo l'ordinamento\n");
    stampaLista(head);

    return 0;
}

Scuola* leggiFileCsv(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Errore durante l'apertura del file\n");
        return NULL;
    }

    Scuola* head = NULL;
    Scuola* current = NULL;

    char linea[100];
    fgets(linea, 100, file); // Salta l'intestazione
    while (fgets(linea, 100, file) != NULL) {
        char* token = strtok(linea, ",");
        Scuola* nuovaScuola = malloc(sizeof(Scuola));
        //token = strtok(NULL, ",");
        strcpy(nuovaScuola->nome, token);//assegnazione nome
        token = strtok(NULL, ",");
        strcpy(nuovaScuola->citta, token);//assegnazione citta
        token = strtok(NULL, ",");
        strcpy(nuovaScuola->via, token);//assegnazione via
        token = strtok(NULL, ",");
        nuovaScuola->numeroAlunni = atoi(token);//assegnazione nAlunni
        token = strtok(NULL, ",");
        nuovaScuola->valutazione = atof(token);//assegnazione valutazione
        nuovaScuola->next = NULL;

        if (head == NULL) { 
            head = nuovaScuola; 
            current = nuovaScuola;
        } else {
            current->next = nuovaScuola; 
            current = nuovaScuola;
        }
    }

    fclose(file);
    return head;
}

void stampaLista(Scuola* head) {
    Scuola* current = head;
    while (current != NULL) {
        printf("Nome: %s, citta: %s, via: %s, Numero alunni: %d, valutazione: %.2f\n", current->nome, current->citta, current->via, current->numeroAlunni, current->valutazione );
        current = current->next;
    }
}