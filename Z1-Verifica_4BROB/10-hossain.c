#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Libro{
	char titolo[50];
	char autore[50];
	int copie;
	Libro* next; //!! struct
}Libro;

// int leggifile(char *nomefile,Libro **head); //!! se le dichiari all'inizio devono stare dopo il main
// void stampaLista(Libro* head);
// Libro* creaLibro(char* titolo,char* autore,int copie);

Libro* creaLibro(char* titolo,char* autore,int copie)
{
	Libro* nuovoLibro=(Libro*)malloc(sizeof(Libro));
	strcpy(nuovoLibro->titolo,titolo);
    strcpy(nuovoLibro->autore,autore);
    nuovoLibro->copie = copie;
    nuovoLibro->next = NULL;

	return nuovoLibro;
}

int leggifile(char nomefile,Libro **head)
{
	FILE *file=fopen(nomefile,"r");
	if(file==NULL)
	{
    return 1;
    }

    char buffer[1000];
    while(fgets(buffer,sizeof(buffer),file)!=NULL)
    {
    char titolo[50];
    char autore[50];
    int copie;

    sscanf(buffer,"%[^,], %[^,], %d",titolo,autore,&copie);	
    Libro* nuovoLibro=creaLibro(titolo,autore,copie);

    nuovoLibro->next=*head;
    *head=nuovoLibro;
    }
    return 0;
}

void stampaLista(Libro* head) {
    while (head) 
    {
        printf("Titolo: %s, Autore: %s, Copie: %d\n",head->titolo, head->autore,head->copie);
        head = head->next;
    }
}

int main(){

    Libro* libri=(Libro*)malloc(sizeof(Libro));

    leggifile("Libri.csv",&libri);

    stampaLista(libri);

    return 0;

}

/*
PARTE 1
Leggi il file .csv e inserisci i dati dentro una lista
Crea una funzione per la stampa della lista e stampa su console
 */


/*
PARTE 2
Inserisci libro:
richiedi in input i dati
all'INIZIO della linkedList
 */



/*
PARTE 3
Ordina la LinkedList in base al numero di libri in ordine decrescente
 */

