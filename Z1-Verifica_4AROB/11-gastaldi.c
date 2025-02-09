
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Libro
{
    char titolo[100];
    char autore[100];
    int copie;
} Libro;

int conteggioRighe(FILE *fp)
{
    char buffer[1024];
    int cont = 0;

    while (fgets(buffer, 1024, fp) != NULL)
    {
        cont++;
    }
    rewind(fp);
    return cont;
}

void caricaDaFile(Libro *biblioteca, int nRighe, FILE *fp)
{

    char buffer[1024];
    Libro *p = biblioteca; // puntatore che scorre

    while (p < (biblioteca + nRighe) && fgets(buffer, 1024, fp) != NULL)
    {
        char *token = strtok(buffer, ",");
        strcpy(p->titolo, token);

        token = strtok(NULL, ",");
        strcpy(p->autore, token);

        token = strtok(NULL, ",");
        p->copie = atoi(token);

        printf("%s %s %d\n", p->titolo, p->autore, p->copie);
        p++;
    }
}

void aggiungiLibro(Libro *biblioteca, int nRighe)
{
    Libro *p = biblioteca + nRighe;
    int n = 1;
    char titolo[100] = "ciao";
    char autore[100] = "gastaldi";
    strcpy(p->titolo, titolo);
    strcpy(p->autore, autore);
    p->copie = n;
}

void visualizzaBiblioteca(Libro *biblioteca, int nRighe)
{
    for (Libro *p = biblioteca; p < (biblioteca + nRighe); p++)
    {
        printf("%s %s %d\n", p->titolo, p->autore, p->copie);
    }
}

void modificaLibro(Libro *biblioteca, int nRighe){
    Libro *p = biblioteca;
    int tro = -1;
    char tit[100];
    printf("inserisci titolo: ");
    scanf("%s", tit);

    while(tro == -1 && p < (biblioteca + nRighe)){
        if(strcmp(p->titolo, tit)== 0){
            int cop;
            printf("inserisci copie: ");
            scanf("%d", &cop);

            p->copie = cop;
            printf("le copie di %s sono state cambiate con %d\n", p->titolo, p->copie);
            tro = 0; //esce dal while perchè l'ha trovato
        }else{
            p++;
        }
    }
    if(tro == -1){
        printf("titolo non trovato\n");
    }

}

void scambioStringa(char *x, char *y){
    char temp[100];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void scambioInt(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(Libro *biblioteca, int nRighe){
    int sup;
    Libro *p;

    for(sup = nRighe - 1; sup > 0; sup--){
        for(p = biblioteca; p < (biblioteca + sup); p++){
            if(p->copie > (p+1)->copie){
                scambioStringa(p->autore, (p+1)->autore);
                scambioStringa(p->titolo, (p+1)->titolo);
                scambioInt(&(p->copie), &((p+1)->copie));
            }
        }
    }
}

int main()
{
    FILE *fp;
    fp = fopen("Libri.csv", "r");
    if (fp == NULL)
    {
        printf("errore con il file");
    }

    int nRighe = conteggioRighe(fp);

    // printf("%d", nRighe);

    Libro *biblioteca = (Libro *)calloc(nRighe, sizeof(Libro));

    if (biblioteca == NULL)
    {
        printf("errore nell'allocazione in memoria");
    }

    caricaDaFile(biblioteca, nRighe, fp);

    fclose(fp);

    int agg = 1;

    int scelta;

    do
    {
        printf("inserisci:\n1 per aggiungere libro\n2 per visualizzare biblioteca\n3 per modificare libro\n4 per ordinare\n5esci\n-> ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                biblioteca = (Libro *)realloc(biblioteca, (nRighe + agg) * sizeof(Libro));
                aggiungiLibro(biblioteca, nRighe);
                nRighe = nRighe + agg;
                break;
            case 2:
                visualizzaBiblioteca(biblioteca, nRighe);
                break;
            case 3:
                modificaLibro(biblioteca, nRighe);
                break;
            case 4:
                bubbleSort(biblioteca, nRighe);
                break;
        } 
    }while(scelta != 5);

    free(biblioteca);
    
    return 0;
}
