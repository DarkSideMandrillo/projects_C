
/*Scrivi un programma in C che permetta di gestire dinamicamente una biblioteca di libri. Ogni libro è rappresentato da una struttura contenente il titolo, l'autore e il numero di copie disponibili. Il programma deve permettere all'utente di aggiungere, modificare e ordinare i libri. L’inventario viene preso da un file CSV.
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

fscanf(file,%49[^\n]",variabile) // Leggere 50 caratteri o fino ad \n */

#include <stdlib.h>
#include <stdio.h>

#include <string.h>//!! mancava

typedef struct Libro
{                     // definisco una struttura libro
    char titolo[100]; // Il titolo del libro.
    char autore[100]; // L'autore del libro.
    int copie;        // Il numero di copie disponibili.
} Libro;

int leggiFile(FILE *fp) //!! tutto maiusc
{ // apro il file e conto quante righe ha

    int cont = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != "NULL")
    {
        cont++;
    }
    rewind(fp);
    return cont;
}

void salvaDaFile(Libro *biblioteca, int cont, FILE *fp)
{
    Libro *pp = biblioteca;
    while (fgets(buffer, 1024, fp) != "NULL")
    {
        Libro *token;
        pp->titolo = strtok(token, ",");
        pp->autore = strtok(token, ",");
        pp->copie = atoi(token, "/n");
    }
}

void stampaBiblioteca(Libro *biblioteca, int cont)
{
    for (Libro *pp = biblioteca; pp < biblioteca + cont; pp++)
    {
        printf("%s %s %d", pp->titolo, pp->autore, pp->copie);
    }
}

void addLibri(Libro *biblioteca, int nRighe, int inPiu)
{
    int cont = nRighe + 1;
    Libro *pp = biblioteca;
    for (cont = nRighe + 1; cont < inPiu + nRighe; cont++)
    {
        strcpy(pp->titolo, "ciao");
        strcpy(pp->autore, "alice");
        pp->copie = 2;
    }
}

void modificaLibro(Libro *biblioteca, int cont, String tit, int cop) //!!non esiste string
{
    Libro *pp = biblioteca;
    int tro = 0;

    while (pp < biblioteca + cont && tro == 0)
    {
        if (strcmp(pp->titolo, tit) == 0)
        {
            pp->copie = cop;
            tro = 0;
        }
    }
}

void ordinaBiblioteca(Libro *biblioteca, int cont)
{
    int *p = cont;
    int sup;
    for (sup = *biblioteca; sup > 0; sup--)
    {
        if (p > (p + 1))
        {
            scambio(p, p + 1)
        }
    }
}

void scambio(int *p)
{
    int *temp;
    int *x = p;
    int *y;
    temp = x;
    x = y;
    temp = y;
}

int main()
{
    File *fp = open("Libri.csv", "r");
    int nRighe = leggiFile(fp);
    int scelta;

    Libro *biblioteca = ((Libro *)calloc(nRighe, sizeof(Libro)));
    salvaDaFile(biblioteca, nRighe, fp);

    do
    {
        printf("Scegli 1 per aggiungere libri, \n2 per visualizzare la biblioteca, \n3 per vedere tutti i libri, \n4 per modificare un libro, \n5 per ordinare la biblioteca, \n6 per uscire);");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            int nAggiunti = 0;
            printf("inserisci quanti libri vuoi aggiungere");
            scanf("%d", &nAggiunti);
            biblioteca = ((Libro *)realloc(nRighe + nAggiunti, sizeof(Libro)));
            addLibri(biblioteca, nRighe, nAggiunti);
            break;
        case 2:
            stampaBiblioteca(biblioteca, nRighe);
            break;
        case 4:
            printf("inserisci il titolo ");
            fflush(stdin);
            scanf("%s", tit);
            printf("\ninserisci il numero di copie ");
            scanf("%d", cop);
            modificaLibro(biblioteca, nRighe, tit, cop);
            break;
        case 5:
            ordinaBiblioteca(biblioteca, nRighe);
            break;
        }

    } while (scelta != 6);

    free(biblioteca);
    fclose(fp);
}
