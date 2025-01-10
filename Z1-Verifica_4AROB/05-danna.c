
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_MAX 1024

typedef struct Libro
{

    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int leggiRigheFile(FILE *fp)
{
    int nRighe = 0;
    char buffer[DIM_MAX];
    fgets(buffer, 1024, fp); // saltiamo la prima riga
    while (fgets(buffer, 1024, fp))
    { // leggo tutta la riga
        nRighe++;
    }
    rewind(fp);
    return nRighe; // ritorniamo il numero di righe
}

void creaStruttura(Libro *libri, FILE *fp, int n)
{
    Libro *punt=libri; // puntatore d'appoggio. //!! o lo inizializzi o usi direttamente libri
    char buffer[DIM_MAX];
    fgets(buffer, 1024, fp);
    while (fgets(buffer, 1024, fp)) //!! errorino
    {
        char *token = strtok(buffer, ","); // dentro al pntatore token ci metto la prima parte della riga fino alla prima virgola che mi trova
        strcpy(punt->titolo, token);       // metto dentro alla struttura
        token = strtok(NULL, ",");         // mi legge fino a quando non trova la virgola se è NULL si ferma
        strcpy(punt->autore, token);       // strcpy perchè sono delle stringhe
        token = strtok(NULL, ",");
        punt->copie = atoi(token); // atoi trasforma in stringa un intero
        punt++;
    }
}

void aggiungiLibri(Libro *libri, int nNuovi, int nVecchi)
{
    char nome[DIM_MAX];
    char tito[DIM_MAX];
    char nCopie[DIM_MAX];
    Libro *punt; // puntatore d'appoggio
    for (punt = libri + nVecchi; punt < libri + (nNuovi + nVecchi); punt++)
    {
        printf("Inserire un titolo nuovo -> ");
        fflush(stdin);
        gets(tito);
        strcpy(punt->titolo, tito);
        printf("Inserire un nuovo autore -> ");
        fflush(stdin);
        gets(nome);
        strcpy(punt->autore, nome);
        printf("Inserire un nuovo numero di copie ->");
        scanf("%s", nCopie);
        strcpy(punt->copie, nCopie);
    }
}

void visualizzaBiblioteca(Libro *libri, int n)
{
    Libro *punt; // puntatore d'appoggio
    for (punt = libri; punt < libri + n; punt++)
    {
        printf("%s %s %d", punt->titolo, punt->autore, punt->copie);
    }
}

int modifica(Libro *libri, char tito, int n)
{
    int cont = 0;
    int tro = -1;
    Libro *punt; // puntatore d'appoggio
    while (tro == -1 && punt < libri + n)
    {
        if (strcmp(punt->titolo, tito) == 0)
        {
            tro = cont;
        }
        else
        {
            cont++;
            punt++;
        }
    }
    return tro;
}

void ordinaStrutture(Libro *libri, int n)
{
    int sup;
    Libro *punt;
    for (sup = n - 1; sup > 0; sup--)
    {
        for (punt = libri; punt < libri + sup; punt++)
        {
            if (punt->copie > (punt + 1)->copie)
            {
                //scambio(); // scambi
            }
        }
    }
}

int main()
{

    FILE *fp;
    fp = fopen("Libri.csv", "r"); // lo apro in read
    if (!fp)
    {
        perror("File non aperto");
        return -1;
    } // controllo del file

    int nRighe = leggiRigheFile(fp);
    Libro *libro;                                   // creo puntatore di un array di strutture
    libro = (Libro *)calloc(nRighe, sizeof(Libro)); // trovo l'area di memoria gia pulita grazie alla calloc
    creaStruttura(libro, fp, nRighe);

    // dati per menù:
    char risposta[DIM_MAX];
    int scelta;
    int nLibriNuovi;
    char titolo2[DIM_MAX];
    Libro *punt2; // per il num copie
    char nuoveCopie[DIM_MAX];
    printf("Inserire una risposta -> ");
    fflush(stdin);
    scanf("%s", risposta);
    while (strcmp(risposta, "si") != 0)
    { // finchè a riposta è diversa da si
        printf("Inserire una scelta 1, 2 , 3 , 4 -> ");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            printf("Inserire quanti prodotti vuoi aggiungere -> ");
            scanf("%d", &nLibriNuovi);
            libro = (Libro *)realloc(libro, (nLibriNuovi + nRighe) * sizeof(Libro)); // aggiungo nProdotti all'area di memoria
            aggiungiLibri(libro, nLibriNuovi, nRighe);
            nRighe = nRighe + nLibriNuovi;
            break;
        case 2:
            visualizzaBiblioteca(libro, nRighe);
            break;
        case 3:
            printf("Inserisci un titolo -> ");
            fflush(stdin);
            gets(titolo2);
            int tro = modifica(libro, titolo2, nRighe);
            if (tro == -1)
                printf("Il titolo non è stato trovato");
            else
            {
                punt2 = libro + tro;
                printf("Inserire un nuovo nome di copie -> ");
                strcpy(punt2->copie, nuoveCopie);
            }

        case 4:
            ordinaStrutture(libro, nRighe);

            printf("Vuoi uscire? ");
            fflush(stdin);
            scanf("%s", risposta);
        }
    }
}
