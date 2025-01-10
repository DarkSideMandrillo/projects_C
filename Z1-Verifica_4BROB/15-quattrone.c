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

#define MAXCHAR 1024

typedef struct scuole   
{
    char nome[MAXCHAR];
    char citta[MAXCHAR];
    char via[MAXCHAR];
    int numeroAlunni;
    float valutazioneScuola;
    struct scuole* next;
}scuole;

void controlloFile(FILE* f){
    if (f == NULL)
    {
        perror("Il file non si è aperto correttamente");
    }else{
        printf("Il file si è aperto correttamente");
    }
}

void liberaMemoria(scuole *head) {
    while (head != NULL) {
        scuole *temp = head;
        head = head->next;
        free(temp);
    }
}

void stampaLista(scuole *head, const char *messaggio) {
    printf("\n%s\n", messaggio);
    scuole *temp = head;
    while (temp != NULL) {
        printf("%s,%s,%s,%d,%.2f\n", temp->nome,temp->citta,temp->citta,temp->via,temp->numeroAlunni,temp->valutazioneScuola);
        temp = temp->next;
    }
}

int main(){
    scuole *head = NULL;
    scuole *tail = NULL;
    FILE *fp = fopen("elencoScuole.csv", "r");
    controlloFile(fp);
    
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);
    
    //Lettura del file csv
    while (!feof(fp)) {
        scuole *nuovo = (scuole*)malloc(sizeof(scuole));
        if (nuovo == NULL) {
            printf("Errore di allocazione memoria.\n");
            break;
        }

        if (fscanf(fp, "%s,%s,%s,%d,%f", nuovo->nome,nuovo->citta, nuovo->via,&nuovo->numeroAlunni, &nuovo->valutazioneScuola) != EOF) {
            free(nuovo);
            break; // no
        }

        nuovo->next = NULL;
        if (head == NULL) {
            head = tail = nuovo;
        } else {
            tail->next = nuovo;
            tail = nuovo;
        }
    }

    stampaLista(head, "Contenuto File");

    fclose(fp);
    liberaMemoria(head);
}