#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione della struttura Studenti
typedef struct //!!Studente
{
    int ID;
    char nome[20];
    char cognome[20];
    char classe[2];
    int eta;
} Studente;

void leggiFileCSV(Studente *studenti, int numStudenti)
{
    int i = 0;
    FILE *file = fopen("student_list.csv", "r");
    if (file == NULL)
    {
        perror("Errore apertura file");
        exit(1);
    }

    char buffer[256]; //!! taglia prima riga
    while (fgets(buffer, sizeof(buffer), file))
    {
        (numStudenti)++;
    }

    rewind(file);

    studenti = (Studente *)malloc(numStudenti * sizeof(Studente));

    while (fgets(buffer, sizeof(buffer), file))
    {
        //!! non così
        sscanf(buffer, "%d, %s ,%s ,%s ,%d", &(studenti)[i].ID, (studenti)[i].nome, (studenti)[i].cognome, (studenti)[i].classe, &(studenti)[i].eta);
        i++;
    }
    fclose(file);
}

// Funzione per aggiungere un nuovo studente
void aggiungiStudente(Studente *studenti, int numStudenti)
{
    numStudenti += 1; //!! passato per copy
    studenti = (Studente *)realloc(studenti, numStudenti * sizeof(Studente));

    Studente *nuovoStudente = &(studenti)[numStudenti - 1];
    nuovoStudente->ID = numStudenti;

    printf("Inserisci il nome del studente: ");
    scanf(" %s", nuovoStudente->nome);

    printf("Inserisci il cognome del studente: ");
    scanf(" %s", nuovoStudente->cognome);

    printf("Inserisci la classe del studente: ");
    scanf(" %s", nuovoStudente->classe);

    printf("Inserisci l'età del studente: ");
    scanf("%d", &nuovoStudente->eta);
}

// Funzione per visualizzare tutti gli studenti
int leggiRigheFile(FILE *file)
{
    int n_righe = 0;
    char buffer[1024];
    //!! devi togliere la prima riga
    while (fgets(buffer, 1024, file) != NULL)
    {
        n_righe++;
    }
    rewind(file);
    return n_righe;
}

// Funzione per eliminare gli studenti in base alla classe
void eliminaStudentiPerClasse(Studente *studenti, int numStudenti)
{
    char classe[2];
    int newNumStudenti = 0;

    printf("Inserisci la classe da eliminare: ");
    scanf(" %s", classe);

    for (int i = 0; i < numStudenti; i++)
    {
        if (strcmp((studenti)[i].classe, classe) != 0)
        {
        }
    }
}//!! mancavano parentesi

int main()
{
    Studente *studenti = NULL;
    int numStudenti = 0;
    int scelta;

    // Leggi i dati dal file CSV e carica gli studenti
    leggiFileCSV(studenti, numStudenti);

    // Menu di scelta delle operazioni
    do
    {
        printf("\nMenu:\n");
        printf("0 Esci\n");
        printf("1 Aggiungi studente\n");
        printf("2 Visualizza studenti\n");
        printf("3 Elimina studenti per classe\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 0:

            break;
        case 1:
            aggiungiStudente(studenti, numStudenti);
            break;
        case 2:
            for (int i = 0; i < numStudenti; i++)
            {
                printf("ID: %d\tNome: %s\tCognome: %s\tClasse: %s\tEtà: %d\n", studenti[i].ID, studenti[i].nome, studenti[i].cognome, studenti[i].classe, studenti[i].eta);
            }
            break;

        case 3:
            eliminaStudentiPerClasse(studenti, numStudenti);
            break;
        default:
            return 0;
        }
    } while (scelta != 0);

    free(studenti);
    return 0;
}
