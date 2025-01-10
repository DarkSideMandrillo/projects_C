
/*
Scrivi un programma in C che permetta di gestire dinamicamente una biblioteca di libri. Ogni libro è rappresentato da una struttura contenente il titolo, l'autore e il numero di copie disponibili. Il programma deve permettere all'utente di aggiungere, modificare e ordinare i libri. L’inventario viene preso da un file CSV.
Struttura:
Definisci una struct chiamata Libro con i seguenti campi:
char titolo[100]: Il titolo del libro.
char autore[100]: L'autore del libro.
int copie: Il numero di copie disponibili.
Input dinamico:
Leggi il file Libri.csv.
Usa calloc per allocare dinamicamente un array di strutture Libro di dimensione uguale al numero di libri presenti.
Inserisci i dati leggendo il file.
Funzionalità:
Il programma deve offrire le seguenti operazioni tramite un menu:
Aggiungi libri:
Permetti all'utente di aggiungere nuovi libri espandendo dinamicamente l'inventario.
Non è richiesto l’input per scegliere i dati del nuovo libro.
Visualizza biblioteca:
Mostra tutti i libri inseriti, con titolo, autore e numero di copie.
Modifica libro:
Cerca un libro per titolo e, se esiste, permette di modificarne il numero di copie.
Ordina biblioteca:
Ordina l’array in base al numero di copie disponibili, in ordine crescente o decrescente.
Richieste aggiuntive
Gestisci correttamente la memoria
Commenta il codice
Usa le funzioni

Comandi utili:
(sono solo un esempio di aiuto)
rewind(file); // Ripristina il puntatore del file all'inizio

fscanf(file,%49[^\n]",variabile) // Leggere 50 caratteri o fino ad \n
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LUNG 1024

typedef struct Libro
{
    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int leggiRigheFile(FILE *fp)
{
    char buffer[LUNG];
    int nRighe = 0;
    //!! anche qua devi togliere la riga 1
    while (fgets(buffer, 1024, fp))
    {
        nRighe++;
    }
    rewind(fp); //!! messo prima!
    return nRighe;
}

void inserisciDatiBiblioteca(Libro *biblioteca, int nLibri, FILE *fp)
{
    char buffer[LUNG];
    Libro *p;
    p = biblioteca;

    // salto la prima riga
    fgets(buffer, LUNG, fp);

    while (fgets(buffer, LUNG, fp))
    { //!! err && p < biblioteca + nLibri
        char *token = strtok(buffer, ",");
        strcpy(p->titolo, token);

        token = strtok(NULL, ",");
        strcpy(p->autore, token);

        token = strtok(NULL, ",");
        p->copie = atoi(token);

        p++;
    }

    rewind(fp); //!! non serve, si puo chiudere
}

void aggiungiLibri(Libro *biblioteca, int libriAggiunti, int nLibri, int nuovaDim)
{
    Libro *p;

    for (p = biblioteca + nLibri; p < biblioteca + nuovaDim; p++)
    {
        printf("Inserisci il titolo: ");
        fflush(stdin);
        scanf("%s", p->titolo);

        printf("Inserisci il nome dell'autore: ");
        fflush(stdin);
        scanf("%s", p->autore);

        printf("Inserisci il numero di copie: ");
        scanf("%d", &p->copie);
    }
}

void visualizzaBiblioteca(Libro *biblioteca, int nLibri)
{
    Libro *p;
    for (p = biblioteca; p < biblioteca + nLibri; p++)
    {
        printf("\nTitolo: %s, Autore: %s, Copie: %d", p->titolo, p->autore, p->copie);
    }
}

void modificaLibro(Libro *biblioteca, int nLibri)
{
    char nomeX[100];
    printf("Inserisci il titolo del libro che vuoi modificare: ");
    fflush(stdin);
    scanf("%s", nomeX); // titolo del libro che si vuole cercare

    int trovato = -1; // esco dal while con trovato = 1, trovato == -1 --> libro non è stato trovato

    Libro *p;
    p = biblioteca;

    while (p < biblioteca + nLibri && trovato == -1)
    {
        if (strcmp(nomeX, p->titolo)) //!!==0
        {
            printf("Inserisci il nuovo numero di copie: ");
            scanf("%d", &p->copie);
        }
        p++;
    }

    if (trovato == -1)
    { // trovato == -1 --> libro non è stato trovato
        printf("Il libro che stavi cercando non esiste!!!");
    }
}

void bubbleSortBiblioteca(Libro *biblioteca, int nLibri)
{
    int sup;
    Libro *p;

    // for(sup = nLibri - 1; sup > 0; sup--){
    //     for(p = )
    // }
}

int main()
{
    int nLibri; // numero di libri presenti nel file
    FILE *fp;
    fp = fopen("Libri.csv", "r"); // apro file in lettura

    // funzione leggere righe file, quanti libri ci sono
    nLibri = leggiRigheFile(fp);

    // alloco dinamicamento un array di strutture inventario
    Libro *biblioteca = (Libro *)calloc(nLibri, sizeof(Libro));

    // inserire i dati nella struttura
    inserisciDatiBiblioteca(biblioteca, nLibri, fp);

    // chiudo il file
    fclose(fp);

    int scelta = 0;

    while (scelta != 5)
    {
        // programma a menu per far decidere all'utente cosa fare
        // esco dal while quando l'utente preme 4
        printf("Premi 1 per aggiungere un libro; \n");
        printf("Premi 2 per visualizzare l'inventario; \n");
        printf("Premi 3 per modificare un libro; ");
        printf("Premi 4 per ordinare l'inventario; ");
        printf("Premi 5 per uscire dal programma --> ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            // Aggiungi libri:
            // Permetti all'utente di aggiungere nuovi libri espandendo dinamicamente l'inventario.
            // Non è richiesto l’input per scegliere i dati del nuovo libro.

            int libriAggiunti; // numero di libri che vuole aggiungere l'utente
            printf("Quanti libri vuoi inserire? ");
            scanf("%d", &libriAggiunti);

            // realloc per riallocare lo spazio in memoria di biblioteca aggiungendo i nuovi libri
            int nuovaDim = nLibri + libriAggiunti; // nuova dimensione

            biblioteca = (Libro *)realloc(biblioteca, nuovaDim * sizeof(Libro));

            aggiungiLibri(biblioteca, libriAggiunti, nLibri, nuovaDim);

            nLibri = nuovaDim;

            break;

        case 2:
            // Visualizza biblioteca:
            // Mostra tutti i libri inseriti, con titolo, autore e numero di copie.
            visualizzaBiblioteca(biblioteca, nLibri);
            break;

        case 3:
            // Modifica libro:
            // Cerca un libro per titolo e, se esiste, permette di modificarne
            // il numero di copie.
            modificaLibro(biblioteca, nLibri);
            break;

        case 4:
            // Ordina biblioteca:
            // Ordina l’array in base al numero di copie disponibili, in ordine crescente o decrescente.
            bubbleSortBiblioteca(biblioteca, nLibri);
        }
    }

    printf("Sei uscito dal programma");
    return 0;
}
