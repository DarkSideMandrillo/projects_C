
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Libro{
    char titolo[100];
    char autore[100];
    int copie;
}Libro;

//funzione che mi restituisce il numero di righe presenti nel file
int leggiRighe(char nome[]){ //!! manca []
    int nRighe;
    char buffer[1024]; //!! char
    FILE *fp = fopen(nome, "r");
    //!! prima riga da togliere
    while(fgets(buffer, 1024, fp) != NULL){
        nRighe++;
    }

    return nRighe;
}

//funzione che legge i valori dal file e mi carica i valori sulla truttura libro
void caricaLibri(Libro *libreria, int nLibri){
    Libro *p;
    char buffer[1024];
    FILE *fp = fopen("Libri.csv", "r");

//controllo che l'apertura del file sia andata a buon fine
    if(!fp){
        printf("errore nell'apertura del file!");
    }else{
        for(p = libreria; p < libreria + nLibri; p++){
            char *token; //manca *
            //leggo una riga del file
            fgets(buffer, 1024, fp);
            //prendo tutto ciò che c'è prima della virgola nella riga del file salvata in buffer partendo dall'inizio
            token = strtok(buffer, ",");
            *p->titolo = token; //!! manca strcpy
            //prendo tutto ciò che c'è prima della virgola nella riga del file salvata in buffer partendo da dove si era fermato prima
            token = strtok(NULL, ",");
            *p->titolo = token;
            //prendo tutto ciò che c'è prima della virgola nella riga del file salvata in buffer partendo da dove si era fermato prima
            token = strtok(NULL, ",");
            *p->titolo = toi(token);

        }
    }

    fclose(fp);
}

//funzione che mi stampa tutti i dati salvati nella struttura
void visualizza(Libro *libreria, int nLibri){
    Libro *p;
    for(p = libreria; p < libreria + nLibri; p++){
        printf("\nTitolo: %s \nAutore: %s \nNumero di copie. %d", p->titolo, p->autore, p->copie);
    }
}

//funzione che mi controlla se i dati inseriti dall'utente esistono nella struttura e se esistono gli permette di modificare il numero di copie del libro
void modifica(Libro* libreria, int nLibri, char autore, char titolo){
    bool tro = false;
    int nc;

    Libro * p = libreria;

    while(tro == false && p < libreria + nLibri){
        if(strcmp(autore, p->autore) == 0 && strcmp(titolo, p->titolo) == 0){
            printf("quante copie vuoi inserire? ");
            scanf("%d", nc);
            p->copie = nc;
        }
        p++;
    }

    if(!tro){
        printf("libro non trovato!");
    }
}

//scambio di due variabili caratteri
void scambioS(char *x, char *y){
    char temp[100];

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

//scambio di due variabili intere
void scambioI(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = *x;
}

void ordinaCrescente(Libro *a, int n){
    int sup;
    Libro *p;
    for(sup = n-1; sup > 0; sup--){
        for(p = a; p < (a+n); p++){
            if(p->copie > (p+1)->copie){
                scambioS(p->autore, (p+1)->autore);
                scambioS(p->titolo, (p+1)->titolo);
                scambioI(p->copie, (p+1)->copie);
            }
        }
    }
}

void ordinaDecrescente(Libro *a, int n){
    int sup;
    Libro *p;
    for(sup = n-1; sup > 0; sup--){
        for(p = a; p < (a+n); p++){
            if(p->copie < (p+1)->copie){
                scambioS(p->autore, (p+1)->autore);
                scambioS(p->titolo, (p+1)->titolo);
                scambioI(p->copie, (p+1)->copie);
            }
        }
    }
}

int main(){
    int nLibri = leggiRighe("Libri.csv");

//alloco spazio in memoria
    Libro *libreria = (Libro *)calloc(nLibri, sizeof(Libro));
//controllo non ci siano stati errori nell'allocazione in memoria
    if(libreria == NULL){
        printf("ERRORE nell'allocazione di memoria!");
        return 1;
    }else{
        int scelta;

        caricaLibri(libreria, nLibri);

        do{
            do{
                printf("MENU: \n1. aggiungi libri \n2. visualizza biblioteca \n3. Modifica libro \n4. ordina biblioteca in modo crescente \n5.ordina biblioteca in modo decrescente \n0. esci \nscelta: ");
                scanf("%d", scelta);
            }while(scelta < 0 || scelta > 5);

            switch (scelta)
            {
            case 1:
                libreria = (Libro *)realloc(libreria, 1 * sizeof(Libro));
                Libro *p = libreria;
                strcpy((p+nLibri)->titolo,"Commedia");
                strcpy((p+nLibri)->autore,"Arianna");
                (p+nLibri)->copie = 10;
                nLibri++;
                break;
            case 2:
                visualizza(libreria, nLibri);
                break;
            case 3:
                char a[100], t[100];
                printf("inserisci il titolo del libro che vuoi modificare: ");
                fflush(stdin);
                scanf("%s", a);
                printf("inserisci l'autore del libro che vuoi modificare: ");
                fflush(stdin);
                scanf("%s", t);
                modifica(libreria, nLibri, a, t);
                break;
            case 4:
                ordinaCrescente(libreria, nLibri);
                break;
            case 5:
                ordinaDecrescente(libreria, nLibri);
                break;
            case 0:
                //l'utenet vuole uscire
                break;
            }
        }while(scelta != 0);
    }

    printf("seiuscito dal programma");

    free(libreria);
}
