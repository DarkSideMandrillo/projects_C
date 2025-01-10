#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_CLIENTE 50
#define MAX_STATO 10
#define FILE_SALVATAGGIO "salvataggio.csv"

typedef struct {
    int id;
    char stato[MAX_STATO];
    char nomeCliente[MAX_NOME_CLIENTE];
} Posto;

// Funzione per caricare i dati dal file
int caricaDati(Posto **posti) {
    FILE *file = fopen(FILE_SALVATAGGIO, "r");
    if (!file) {
        printf("Impossibile aprire il file di salvataggio.\n");
        return 0;
    }

    // Conta il numero di righe nel file
    int numPosti = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        numPosti++;
    }
    rewind(file); // Ripristina il puntatore del file all'inizio

    // Alloca memoria per i posti usando calloc
    *posti = (Posto *)calloc(numPosti, sizeof(Posto));
    if (!*posti) {
        printf("Errore di allocazione della memoria.\n");
        fclose(file);
        return 0;
    }

    // Carica i dati nel vettore di strutture
    int i = 0;
    while (fscanf(file, "%d,%9s,%49[^\n]\n", &(*posti)[i].id, (*posti)[i].stato, (*posti)[i].nomeCliente) == 3) {
        i++;
    }

    fclose(file);
    return numPosti; // Restituisce il numero di posti caricati
}

// Funzione per salvare i dati su file
void salvaDati(Posto *posti, int numPosti) {
    FILE *file = fopen(FILE_SALVATAGGIO, "w");
    if (!file) {
        printf("Impossibile aprire il file di salvataggio per la scrittura.\n");
        return;
    }

    for (int i = 0; i < numPosti; i++) {
        fprintf(file, "%d,%s,%s\n", posti[i].id, posti[i].stato, posti[i].nomeCliente);
    }

    fclose(file);
}

int main() {
    Posto *posti = NULL;  // Pointer ai posti
    int numPosti = caricaDati(&posti); // Carica i dati dal file

    if (numPosti == 0) {
        printf("Errore nel caricamento dei dati. Il programma terminerà.\n");
        return 1;
    }

    // Assegna automaticamente gli ID in progressione
    for (int i = 0; i < numPosti; i++) {
        posti[i].id = i + 1; // Gli ID partono da 1
    }

    int scelta;
    do {
        printf("\nMenu:\n");
        printf("1. Prenotare un posto\n");
        printf("2. Liberare un posto\n");
        printf("3. Visualizzare stato della sala\n");
        printf("4. Salvare i dati\n");
        printf("5. Esci\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                int id;
                char nomeCliente[MAX_NOME_CLIENTE];
                printf("Inserisci l'ID del posto da prenotare: ");
                scanf("%d", &id);
                if (id < 1 || id > numPosti) {
                    printf("ID non valido.\n");
                    break;
                }

                if (strcmp(posti[id - 1].stato, "prenotato") == 0) {
                    printf("Il posto %d è già prenotato.\n", id);
                    break;
                }

                printf("Inserisci il nome del cliente: ");
                scanf("%s", nomeCliente);
                strcpy(posti[id - 1].nomeCliente, nomeCliente);
                strcpy(posti[id - 1].stato, "prenotato");

                printf("Posto %d prenotato con successo.\n", id);
                break;
            }
            case 2: {
                int id;
                printf("Inserisci l'ID del posto da liberare: ");
                scanf("%d", &id);
                if (id < 1 || id > numPosti) {
                    printf("ID non valido.\n");
                    break;
                }

                if (strcmp(posti[id - 1].stato, "libero") == 0) {
                    printf("Il posto %d è già libero.\n", id);
                    break;
                }

                strcpy(posti[id - 1].stato, "libero");
                memset(posti[id - 1].nomeCliente, 0, sizeof(posti[id - 1].nomeCliente));

                printf("Posto %d liberato con successo.\n", id);
                break;
            }
            case 3: {
                printf("\nStato della sala:\n");
                for (int i = 0; i < numPosti; i++) {
                    printf("Posto %d - Stato: %s - Cliente: %s\n", posti[i].id, posti[i].stato, posti[i].nomeCliente[0] ? posti[i].nomeCliente : "Nessun cliente");
                }
                break;
            }
            case 4:
                salvaDati(posti, numPosti);
                printf("Dati salvati con successo.\n");
                break;
            case 5:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 5);

    free(posti);  // Libera la memoria allocata
    return 0;
}