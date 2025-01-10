
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struttura libro che andrò poi a popolare
typedef struct Libro
{
    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int rowCount(FILE *fp)
{
    int rowcount = 0;
    char buffer[1024];

    fscanf(fp, "%s, %s, %s", buffer);
    rowcount++;
    while (fscanf(fp, "%s,%s,%d", buffer))
    {
        rowcount++;
    }
    rewind(fp);
    return rowcount;
}

void leggiDatiDaFile(Libro *libri, FILE *fp)
{
    // utilizzo un puntatore d'appoggio per la lettura
    Libro *pp = libri;
    char buffer[1024];
    // salto la prima riga
    fscanf(fp, "%s,%s,%s", buffer);
    while (fscanf(fp, "%s,%s,%d", buffer))
    {
        // Utilizzo il token per suddividermi quello che trovo nel buffer
        char *token = strtok(buffer, ",");

        token = strtok(NULL, ",");
        strcpy(pp->autore, token);

        token = strtok(NULL, ",");
        strcpy(pp->titolo, token);

        token = strtok(NULL, ",");
        pp->copie = atoi(token);
        pp++;
    }
}

void aggiungiLibri(Libro *libri, int nLibriPrec, int nLibriNuovi)
{
    Libro *pp = libri;

    for (pp + nLibriPrec; pp < libri + nLibriPrec + nLibriNuovi; pp++)//!! +
    {
        strcpy(pp->autore, "NuovoAutore");
        strcpy(pp->titolo, "NuovoTitolo");
        pp->copie = 5;
    }
}

void visualizzaTab(Libro *libri, int nLibri)
{
    Libro *pp = libri;
    for (pp; pp < libri + nLibri; pp++)
    {
        printf("%s,%s,%d", pp->autore, pp->titolo, pp->copie);
        printf("\n");
    }
}

void modificaLibro(Libro *libri, int nLibri, char libroCercato[])
{
    Libro *pp = libri;
    bool tro = false;
    int nCopieDiverso;

    while (pp < libri + nLibri && tro == false)
    {
        if (strcmp(pp->titolo, libroCercato))
        {
            tro = true;
            printf("Modifica il numero di copie\n");
            scanf("%d", &nCopieDiverso);
            pp->copie = nCopieDiverso;
        }
        pp++;
    }
}

int main()
{
    // puntatore utile per la lettura del file
    FILE *fp;
    char nomeFile[20] = "Libri.csv";

    // Apro il file in modalità lettura all'inizio
    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        perror("c'è stato un errore nella lettura del file\n");
    }

    // Per sapere quante righe ha il file così da fare la lettura corretta
    int nLibri;

    // leggo le righe del file
    nLibri = rowCount(fp);
    printf("%d", nLibri);

    // Adesso leggo tutti i dati da file dopo aver predisposto lo spazio con calloc
    Libro *libri = (Libro *)calloc(nLibri, sizeof(Libro));
    // leggiDatiDaFile
    leggiDatiDaFile(libri, fp);
    // Non mi serve più il file, ho tutto scritto sulla struttura
    fclose(fp);
    // procedo alle funzionalità aggiuntive trmite menù
    int scelta;
    do
    {
        printf("\nMenù\n");
        printf("1 aggiungi libro\n");
        printf("2 visualizza la bibblioteca\n");
        printf("3 modifica un libro\n");
        printf("4 ordina la bibblioteca\n");
        printf("5 esci\n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            // permetto all'utente di aggiungere un libro
            int nuoviLibri;
            printf("Quanti libri vuoi aggiungere?\n");
            scanf("%d", &nuoviLibri);

            // Utilizzo la realloc per ingrandire lo spazio in memoria che avevo allocato per la struttura da prima
            nLibri+=nuoviLibri;
            libri = (Libro *)realloc(libri, nLibri * sizeof(Libro));
            aggiungiLibri(libri, nLibri, nuoviLibri);
            break;
        case 2:
            // visualizzo la struttura
            visualizzaTabella(libri, nLibri);
            break;
        case 3:
            // modifico un prodotto
            char libroCercato[20];
            Printf("Inserisci il libro che vuoi modificare (Inserisci il titolo)\n");
            scanf("%s", libroCercato);

            modificaLibro(libri, nLibri, libroCercato);
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    while(true);
    return 0;
}
