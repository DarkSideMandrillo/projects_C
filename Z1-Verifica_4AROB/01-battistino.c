
/*Scrivi un programma in C che permetta di gestire dinamicamente una biblioteca di libri. Ogni libro è rappresentato da una struttura contenente il titolo, l'autore e il numero di copie disponibili.
 Il programma deve permettere all'utente di aggiungere, modificare e ordinare i libri. L’inventario viene preso da un file CSV.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM 100
typedef struct Libro
{
    char titolo[DIM];
    char autore[DIM];
    int copie;
} Libro;

int leggiFile(FILE *fp)
{
    char buffer[1024];
    int nRighe = 0;
    //!! Manca rewind()
    while (fgets(buffer, 1024, fp))
    {

        nRighe++;
    }
    return nRighe;
}

void caricaDati(Libro *libri, FILE *fp, int dim)
{
    char buffer[1024];
    int k = 0;

    while (fgets(buffer, 1024, fp))
    {
        char *token = strtok(buffer, ",");
        strcpy(libri[k].titolo, buffer); // usato buffer al posto di token
        token = strtok(NULL, ","); //!! token e non *token
        strcpy(libri[k].autore, buffer);
        token = strtok(NULL, ",");
        libri[k].copie = atoi(token);
        k++;
    }
}

int main()
{
    char nomeFile[] = "Libri.csv"; //!! char nome[]
    FILE *fp = fopen(nomeFile, "r"); //!! manca fopen
    bool ok = false;
    int nRighe = leggiFile(fp); //!! nome func errato
    rewind(fp);

    Libro *libri = (Libro *)calloc(nRighe, sizeof(Libro));
    caricaDati(libri, fp, nRighe);
    fclose(fp);
    do
    {
        int scelta;
        printf("\n 0 esci\n 1 aggiungi libri \n 2 visualizza libreria\n 3 modifica libro \n 4 ordina biblioteca ");
      
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 0:
            ok = true;
            break;

        case 1:
            int libroagg=1;
            Libro *libri=(Libro *)realloc(nRighe, sizeof(Libro));//!! (Libro *)realloc(libri, sizeof(Libro)*nRighe+1)
            //nRighe++
            
            break;

        case 2:
            for (int k = 0; k < nRighe; k++)
            {

                printf("%s %s %d \n ", libri[k].titolo, libri[k].autore, libri[k].copie);
            }

            break;

        case 3:
            bool tro = false;
            int k = 0;
            int nc;
            char titolo[DIM] = "divina commedia";
            while (k < nRighe && tro == false)
            {

                if (strcmp(libri[k].titolo, titolo) == 0)
                {

                    printf("\nquante copie vuoi mettere");
                    scanf("%d", &nc);
                    libri[k].copie = nc;
                    tro = true;
                }else{

                    printf("\nlibro non trovato");
                    
                }
                //!! manca incremento di k
            }

            break;

        case 4:

            break;

        default:
            break;
        }

    } while (ok = false);
}
