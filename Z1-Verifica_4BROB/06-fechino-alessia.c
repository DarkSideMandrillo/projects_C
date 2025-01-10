/*
VALUTAZIONE
Parte 1     | 4pt.  |
Parte 2     | 1pt.  |
Parte 3     | 2pt.  |
CleanCode   | 2pt.  |      

CleanCode = Commenti nel codice, Nome variabili corrette, codice non ripetuto, logica ottimizzata
*/
/*
PARTE 1
Leggi il file .csv e inserisci i dati dentro una lista
Crea una funzione per la stampa della lista e stampa su console
 */


/*
PARTE 2
Inserisci la scuola:
"Istituto Nautico Amerigo Vespucci","Genova","Via del Porto 45",700,4.5
all'INIZIO della linkedList
 */



/*
PARTE 3
Ordina la LinkedList in base al numero di studenti in modo crescente
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LUNGHEZZASTRINGA 100
#define LUNGHEZZARIGA 500

typedef struct Scuola{
    char nome[LUNGHEZZASTRINGA];
    char citta[LUNGHEZZASTRINGA];
    char via[LUNGHEZZASTRINGA];
    int numeroAlunni;
    float valutazione;
    struct Scuola* next;
}Scuola;

void stampaLista(Scuola *nodo);

int main(){
    FILE *file=fopen("elencoScuole.csv","r");
    if(file==NULL){
        perror("Errore nell'apertura del file!");
        return -1;
    }
    else{
        Scuola *indirizzo=NULL; //meglio head
        Scuola *appoggio=NULL;
        char buffer[LUNGHEZZARIGA];
        //lettura file
        fgets(buffer,LUNGHEZZARIGA,file);//mi legge la prima riga di intitolazione che non mi serve

        while (fgets(buffer,LUNGHEZZARIGA,file)!=NULL){
            Scuola *school=(Scuola*)malloc(sizeof(Scuola));
            sscanf(buffer,"%[^,],%[^,],%[^,],%d,%f",school->nome,school->citta,school->via,&school->numeroAlunni,&school->valutazione);
            school->next=NULL;
            if(indirizzo==NULL)
                indirizzo= school;  
            else
                appoggio->next=school;  
            appoggio=school; 
        }
        fclose(file);
        //stampa la lista
        stampaLista(indirizzo);

        //aggiungo una scuola a inizio della lista
        Scuola *newScuola=(Scuola*)malloc(sizeof(Scuola));
        strcpy(newScuola->nome,"Istituto Nautico Amerigo Vespucci");
        strcpy(newScuola->citta,"Genova");
        strcpy(newScuola->via,"Via del Porto 45");
        newScuola->numeroAlunni=700;
        newScuola->valutazione=4.5;
        newScuola->next=indirizzo;
        indirizzo=newScuola;

        //stampa la lista
        stampaLista(indirizzo);

        //ordino la lista in modo crescente del valore numeroAlunni
        bool ordinato=false;
        char stringaAppoggio[LUNGHEZZASTRINGA];
        int numeroAppoggio;
        float realeAppoggio;
        while (ordinato==false)
        {
            appoggio=indirizzo;
            ordinato=true;
            while (appoggio!=NULL)
            {
                if(appoggio->numeroAlunni>appoggio->next->numeroAlunni){
                    ordinato=false;
                    //scambio nomi
                    strcpy(stringaAppoggio,appoggio->nome);
                    strcpy(appoggio->nome,appoggio->next->nome);
                    strcpy(appoggio->next->nome,stringaAppoggio);
                    //scambio città
                    strcpy(stringaAppoggio,appoggio->citta);
                    strcpy(appoggio->citta,appoggio->next->citta);
                    strcpy(appoggio->next->citta,stringaAppoggio);
                    //scambio via
                    strcpy(stringaAppoggio,appoggio->via);
                    strcpy(appoggio->via,appoggio->next->via);
                    strcpy(appoggio->next->via,stringaAppoggio);
                    //scambio numero alunni
                    numeroAppoggio=appoggio->numeroAlunni;
                    appoggio->numeroAlunni=appoggio->next->numeroAlunni;
                    appoggio->next->numeroAlunni=numeroAppoggio;
                    //scambio valutazione
                    realeAppoggio=appoggio->valutazione;
                    appoggio->valutazione=appoggio->next->valutazione;
                    appoggio->next->valutazione=realeAppoggio;
                }
                appoggio=appoggio->next;
            }   
        }
        //stampa la lista
        stampaLista(indirizzo);
        
        //libera la memoria
        // appoggio=indirizzo;
        // Scuola *temp;
        // while (appoggio!=NULL)
        // {
        //     temp=appoggio;
        //     free(temp);
        //     appoggio=appoggio->next;
        // }
    }
    return 0;
}
void stampaLista(Scuola *nodo){
    Scuola *appoggio=nodo;
    while (appoggio!=NULL)
    {
        printf("%s %s %s %d %.2f\n",appoggio->nome,appoggio->citta,appoggio->via,appoggio->numeroAlunni,appoggio->valutazione);
        appoggio=appoggio->next;
    }
    printf("\n");
    free(appoggio); // non nella stampa
}