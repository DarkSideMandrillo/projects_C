
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


typedef struct Libro{
    char titolo[100];
    char autore[100];
    int copie;
}Libro;

int contaRighe(FILE *fp){
    char buffer[1024];
    int n = 0;
    fgets(buffer, 1024, fp);
    while(fgets(buffer, 1024, fp)){
        n++;
    }
    rewind(fp);
    return n;
}

void caricaStruttura(FILE *fp, int nr, Libro *p){
    char buffer[1024];
    Libro *pp = p;
    fgets(buffer, 1024, fp);
    while(fgets(buffer, 1024, fp) && pp < p + nr){
        char *token = (buffer, ","); //!! manca strtok
        strcpy(pp->titolo, token);
        token = (NULL, ",");
        strcpy(pp->autore, token);
        token = (NULL, ",");
        pp->copie = atoi(token);
    }

}

void visualizzaBiblioteca(FILE *fp, int nr, Libro *p){
    Libro *pp;
    for(pp = p; pp < p + nr; pp++){
        printf("%s, %s, %d\n", pp->titolo, pp->autore, pp->copie);
    }
}

void scambio(int *a, int *b){ //!! scambia solo le copie
    int temp;
    temp = *a;
    *a = *b;
    *b = *a;
}

void ordinaBiblioteca(FILE *fp, int nr, Libro *p){
    Libro *pp = p;
    for(int sup = nr - 1; sup > 0; sup--){
        for(pp = p; pp < p + nr; pp++){
            if(pp->copie > (pp+1)->copie){
                scambio(&pp->copie, &(pp+1)->copie);
            }
        }
    }
}

void modificaLibrp(Libro *p, int nr){
    char nomeLib[50];
    int scelta;
    bool trovato = false;
    Libro *pp = p;
    
    printf("inserisci il libro da modificare: ");
    fflush(stdin);
    scanf("%s", nomeLib);

    while(trovato == false && p < pp + nr)
    {
        if (strcmp(pp->titolo, nomeLib) == 0){
            trovato = true;
        }
        p++;
    }

    p--;
}
    //devo finire



int main(){
    FILE *fp;
    fp = fopen("Libri.csv", "r");
    int nr = contaRighe(fp);
    Libro *p = (Libro *) calloc(nr, sizeof(Libro));

    caricaStruttura(fp, nr, p);
    int scelta;
    
    do{
        printf("Inserire la scelta:\n[1]:aggiungi libro; \n[2]:visualizza la biblioteca; \n[3]:modifica libro; \n[4]:ordina biblioteca \n[0]:per uscire.\n");
        scanf("%d", &scelta);
        switch (scelta){
        case 1:
            //aggiungiLibri();
            break;
        case 2:
            visualizzaBiblioteca(fp, nr, p);
            break;
        case 3:
            //modificaLibro(*p, nr);
            break;
        case 4:
            ordinaBiblioteca(fp, nr, p);
        default:
            break;
        }
    }while(scelta != 0);

}
