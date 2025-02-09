
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Libro
{ // Definisci la struttura libro e i suoi campi
    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int leggiFile(FILE *fp)
{

    char buffer[1024];
    int nLibri = 0;

    while (fgets(buffer, 1024, fp))
    {
        nLibri++;
    }

    rewind(fp);
    return nLibri;
}

void caricaDatiDaFile(FILE *fp, Libro *libri, int nLibri)
{

    char buffer[1024];
    Libro *pp = libri;

    fgets(buffer, 1024, fp); // La prima linea non la utilizzo perchè non ci sono i nomi

    while (fgets(buffer, 1024, fp) && pp < libri + nLibri)
    { // Ciclo finchè non ci sono righe
        //!! Manca strcpy()
        char *token = strtok(buffer, ","); // Leggo le due stringhe e uso l'atoi per trasformare la stringa in intero
        pp->titolo = token;

        token = strtok(buffer, ",");
        pp->autore = token;

        token = strtok(buffer, ",");
        pp->copie = atoi(token);

        pp++;
    }
}

void visualizzaBiblioteca(FILE *fp, Libro *libri, int nLibri)
{ // Funzione che visualizza il contenuto del mio file a schermo

    Libro *pp = libri;
    for (pp; pp < libri + nLibri; pp++)
    {
        printf("Titolo: %s  Autore: %s  copie: %d", pp->titolo, pp->autore, pp->copie);
    }
}

void modificaLibro(FILE *fp, Libro *libri, int nLibri)
{ // Creo una funzione che cerca il titolo con lo strcmp e ne modifica il numero di copie
    char nomeLibro[50];
    printf("Inserisci il titolo del libro che vuoi modificare -> ");
    scanf("%s", nomeLibro);

    Libro *pp = libri;
    bool tro = false;

    while (pp < libri + nLibri && tro == false)
    {

        if (strcmp(pp->titolo, nomeLibro) == 0)
        {
            printf("Inserisci il valore da modificare: "); //!! ;
            scanf("%d", &pp->copie); 
        }

        pp++; //!! p non esiste
    }

    if (tro == false)
    {
        printf("Non è stato trovato nessun libro");
    }
}

void ordinaBiblioteca(FILE *fp, Libro *libri, int nLibri)
{ // Funzione che ordina il file in base al numero di copie
}

int main()
{

    char nomeFile[] = "Libri.csv"; // Dò il nome al file e lo apro in modalità lettura. è un []
    FILE *fp = fopen(nomeFile, "r");

    int nLibri = leggiFile(fp); // Trovo il numero di libri con la funzione

    Libro *libri = (Libro *)calloc(nLibri, sizeof(Libro)); // Alloco dinamicamente con la calloc una parte di memoria del numero di libri per la dimensione di ogni libro

    caricaDatiDaFile(fp, libri, nLibri);

    char risp;
    printf("Vuoi aggiungere dei libri? (s o n)");
    fflush(stdin);
    scanf("%c", &risp);

    if (risp == 's')//!! ' e non "
    {
        int num;
        printf("Quanti libri vuoi aggiungere?"); //!! manca ;
        scanf("%d", &num);
        Libro *libriAggiunti = (Libro *)realloc(libri, (num + nLibri) * sizeof(Libro)); // Dopo aver chiesto all'utente se vuole aggiungere qualcosa
    } // Alloco la memoria sommando i libri già presenti a quelli che si vogliono aggiungere

    fclose(fp); // Chiudo il file

    free(libri); // Disalloco la memoria
}
