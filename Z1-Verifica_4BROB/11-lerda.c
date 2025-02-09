/*
Crea una cartella nuova sul desktop
Apri la cartella con VS Code
Copia il file .csv dentro la cartella
Crea un nuovo file main.c e incolla i seguente testo:
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
#define DIM 50
#define DIM_CITTA 10
#define N_SCUOLE 12

typedef struct Scuola{    //struttura di tipo Scuola
    char nomeScuola[DIM];
    char cittaScuola[DIM_CITTA];
    char viaDellaScuola[DIM];
    int numeroAlunni;
    float valutazioneScuola;
    struct Scuola *prossimaScuola;
}Scuola;

int leggiFileCSV (char nomeFile[], Scuola infoScuola[]);  //funzione che legge i prodotti
void stampaInfoScuola (Scuola infoScuola[], int nProdotti); //funzione che stampa i prodotti a schermo
void aggiungiScuolaAllaFine (Scuola infoScuola[]); //funzione che aggiunge un prodotto a fine della lista
void ordinaLaListaPerStudenti (Scuola infoScuola[], int nProdotti); //funzione che ordina in base a numero studenti

int main()
{
    Scuola infoScuola[N_SCUOLE];
    int nProdotti = leggiFileCSV("elencoScuole.csv", infoScuola);
    stampaInfoScuola (infoScuola, nProdotti);



    return 0;
}

int leggiFileCSV (char nomeFile[], Scuola infoScuola[])  //funzione che legge il file csv e ne conta i prodotti
{
    int i=0;
    int nProdotti=0;
    Scuola prossimaScuola[i];
    FILE* file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("Errore nell'aprire il file\n");
    } else{
        char linea[1024];
        infoScuola->prossimaScuola = NULL;
        while (fgets(linea,100, file))
        {
            char *token = strtok(linea, ",");  //lettura del file csv fino alla virgola
            strcpy(infoScuola[i].nomeScuola, token);

            token = strtok(NULL, ",");
            strcpy(infoScuola[i].cittaScuola, token);

            token = strtok(NULL, ",");
            strcpy(infoScuola[i].viaDellaScuola, token);

            token = strtok(NULL, ",");
            infoScuola[i].numeroAlunni = atoi(token);

            token = strtok(NULL, ",");
            float valutazioneScuola = atoi(token);
            infoScuola[i].valutazioneScuola = valutazioneScuola;

            infoScuola[i].prossimaScuola = prossimaScuola;
            i++;
            nProdotti++;
        }
        
    }
    fclose(file);
    return nProdotti;
}

void stampaInfoScuola (Scuola infoScuola[], int nProdotti)  //stampa i dati della lista
{
    for(int i=0; i<nProdotti-1; i++){
        printf("Nome della Scuola: %s \n", infoScuola[i+1].nomeScuola);
        printf("Citta della Scuola: %s \n", infoScuola[i+1].cittaScuola);
        printf("Via della Scuola: %s \n", infoScuola[i+1].viaDellaScuola);
        printf("Numero alunni della Scuola: %d \n", infoScuola[i+1].numeroAlunni);
        printf("Valutazione Scuola: %.2f \n", infoScuola[i+1].valutazioneScuola);
        printf("\n");
    }
}

void aggiungiScuolaAllaFine (Scuola infoScuola[])  //dovrebbe aggiungere alla fine ma probabilmente no, peccato
{
    int i=0;
    Scuola* newScuola = (Scuola*)malloc(sizeof(Scuola));
    newScuola->nomeScuola = "Istituto Nautico Amerigo Vespucci";
    newScuola.cittaScuola = "Genova";
    newScuola[i].viaDellaScuola = "Via del Porto 45";
    newScuola[i].numeroAlunni = 700;
    newScuola[i].valutazioneScuola = 4.5;
    Scuola*primo = newScuola;
    newScuola = primo;
}


void ordinaLaListaPerStudenti(Scuola infoScuola[], int nProdotti)  //avevo iniziato a farla ma non mi veniva, però doveva ordinare im ordine crescente
{
    int max[nProdotti];
    int i=1;
    printf("ordina la lista per numero degli studenti \n");
    if(max[i] < infoScuola[i].numeroAlunni){
            max[i] = infoScuola[i].numeroAlunni;
    }

    for (int i=0; i<nProdotti-1; i++){
        if(max > infoScuola[i].numeroAlunni){
            infoScuola[i].numeroAlunni = max[i+1];
        } else {
            
        }
    }

    
}
