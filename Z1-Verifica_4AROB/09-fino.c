
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Libro
{
    char titolo[100];
    char autore[100];
    int copie;
}Libro;
int numeroRighe(FILE *fp){
    char buffer[1024];
    int num=0;
    fgets(buffer, 1024, fp);
    while (fgets(buffer, 1024, fp))
    {
        num++;
    }
    rewind(fp);
    return num;
}
void leggiStruct(Libro *l, int num, FILE *fp){
    Libro *ll=l;
    char buffer[1024];
    fgets(buffer, 1024, fp);
    while (fgets(buffer, 1024, fp) && ll < l +num)
    {
        char *token=strtok(buffer, ",");
        strcpy(ll->titolo, token);
        token=strtok(NULL, ",");
        strcpy(ll->autore, token);
        token=strtok(NULL, ",");
        ll->copie=atoi(token);
        ll++;
    }
    
}

void stampa(Libro *l, int num){
    for (Libro *ll = l; ll < l+num; ll++)
    {
        printf("%s %s %d\n", ll->titolo, ll->autore, ll->copie);
    }
    
}

void aggiungiLibro(Libro *l, int num){
    Libro *ll=l+1; //!! cosi punti sempre al secondo || Libro *ll = l + (num - 1);
    printf("inserisci il titolo: ");
    fflush(stdin);
    scanf("%s", ll->titolo);
    printf("inserisci l'autore: ");
    fflush(stdin);
    scanf("%s", ll->autore);
    printf("inserisci il numero di copie: ");
    scanf("%d", &ll->copie);
    
}
void modifica(Libro *l, int num){
    char nomeMod[100];
    printf("nome libro da modificare:");
    fflush(stdin);
    scanf("%s", nomeMod);
    Libro *ll=l;
    bool tro=false;
    int nu;
    while (ll<l+num && tro==false)
    {
        if (strcmp(ll->titolo, nomeMod)==0)
        {
            tro=true;
            printf("numero copie:");
            scanf("%d", &nu);
            ll->copie=nu;
        }
        //!! ll++
        
    }
    
}
int main(){
    int scelta;
    FILE *fp=fopen("Libri.csv", "r");
    if(!fp){
        perror("problemi file");
        return 1;
    }
    int num=numeroRighe(fp);
    Libro *l=(Libro *)calloc(num, sizeof(Libro));
    leggiStruct(l, num, fp);
    fclose(fp);
    
    stampa(l, num);
    do
    {
        do
        {
            printf("MENU:\n[0]esci\n[1]aggiungi libri\n[2]visualizza biblioteca\n[3]modifica libro\n[4]ordina biblioteca");
            scanf("%d", &scelta);
        } while (scelta<0 || scelta>4);

        switch (scelta)
        {
        case 1:
            num++;
            l=(Libro *)realloc(l, num * sizeof(Libro)); //!! no nuova var
            aggiungiLibro(l, num);
            break;
        
        case 2:
            stampa(l, num);
            break;
        case 3:
            modifica(l, num);
            break;
        
        
        }
        
    } while (scelta!=0);
    
    return 0;
}
