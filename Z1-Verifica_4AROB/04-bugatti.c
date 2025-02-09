
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h> //!! mancava
typedef struct Libro
{ //!! manca struct e ;
    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int leggiFile(FILE *fp)
{
    int num = 0;
    char buffer[1024];
    fgets(buffer, 1024, fp);
    while (fgets(buffer, 1024, fp))
    {
        num++;
    }
    rewind(fp);
    return num;
}

void assegnadati(FILE *fp, Libro *Biblioteca, int dim)
{
    Libro *pp = Biblioteca;
    int k = 0;
    char buffer[1024];
    fgets(buffer, 1024, fp);
    while (fgets(buffer, 1024, fp) && k < dim)
    {
        char *token = strtok(buffer, ","); 
        strcpy(pp->titolo, token);
        token = strtok(NULL, ","); //!! senza deref
        strcpy(pp->autore, token);
        token = strtok(NULL, ",");
        pp->copie = atoi(token);
        k++;
    }
}

void visualizzadati(Libro *Biblioteca, int dim)
{
    for (Libro *pp = Biblioteca; pp < Biblioteca + dim; pp++)
    {
        printf("Il titolo e' %s l'autore e' %s ed il numero di copie e' %d \n", pp->titolo, pp->autore, pp->copie);
    }
}
void modificadati(Libro *Biblioteca, int dim, char nomelibro[])
{
    Libro *pp = Biblioteca;
    bool tro = false;
    while (pp < Biblioteca + dim && !tro)
    {
        if (strcmp(pp->titolo, nomelibro) == 0)//!! nome non esiste
        {
            printf("libro trovato!\ni dati che vuoi midoficare sono : %s %s %d", pp->titolo, pp->titolo, pp->copie);
            printf("inseire il titolo modificato:");
            fflush(stdin);
            scanf("%s", pp->titolo);
            printf("inseire l'autore:");
            fflush(stdin);
            scanf("%s", pp->autore);
            printf("inseire il numero di copie:");
            scanf("%d", &pp->copie);
        }
    }
}
int main()
{
    FILE *fp = fopen("Libri.csv", "r");
    int num = leggiFile(fp);
    int scelta = -1;
    bool ok = false;
    Libro *Biblioteca = (Libro *)calloc(num, sizeof(Libro));
    assegnadati(fp, Biblioteca, num);

    do
    {
        // menu
        do
        {
            printf("inserire:\n[0] per uscire\n[1] per aggiungere dei libri\n[2]per visualizzare tutta la biblioteca\n[3] per modificare un libro\n[4] per ordinare la biblioteca");
            scanf("%d", &scelta);
        } while (scelta <= 0 || scelta > 4);
        switch (scelta)
        {
        case 0:
            ok = true;
            break;
        case 1:
            int q = 0;
            printf("vuoi aggiungere dei libri: ");
            scanf("%d", &q);
            num += q;

            //caricadatinuovi(Biblioteca, q, num); // funzione che carica nuovi libri //!! manca caricamento
            break;
        case 2:
            visualizzadati(Biblioteca, num); // funzione che visualizza i dati della strutture
            break;

        case 3:
            char tlibro[1024];
            printf("inserire il titolo del librp\n");
            fflush(stdin);
            scanf("%s", tlibro);
            //modificaDati(Biblioteca, num, tlibro); // funzione che modifica i dati della struttura
            break;

        case 4:
            //ordinadati(Biblioteca, num, tlibro); // funziona che ordina i dati della struttura
            break;
        }

    } while (!ok);
    printf("sei uscito!!\n");
    free(Biblioteca);

    return 0;
}
