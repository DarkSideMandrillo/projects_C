#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    char *stringCurrentTime;

    // Otteniamo ora corrente
    currentTime = time(NULL);        // Restituisce il numero di secondi da (1 gennaio 1970, 00:00:00 UTC)
    if (currentTime == ((time_t)-1)) // ((time_t)-1) è IL valore di errore
        exit(EXIT_FAILURE);

    stringCurrentTime = ctime(&currentTime); // Trasformazione in stringa
    if (stringCurrentTime == NULL)
        exit(EXIT_FAILURE);

    printf("L'ora corrente è %s", stringCurrentTime);

    // Inserimento di una data
    struct tm dataSpecifica = {0}; // Creo struttura tm
    time_t tempoSpecifico;

    // Assegno alla struttura i singoli valori
    // Definizione di una data specifica: 25 dicembre 2024, 12:00:00
    dataSpecifica.tm_year = 2024 - 1900; // Anno: 2024 (dal 1900)
    dataSpecifica.tm_mon = 11;           // Mese: dicembre (0 = gennaio, 11 = dicembre)
    dataSpecifica.tm_mday = 25;          // Giorno: 25
    dataSpecifica.tm_hour = 12;          // Ora: 12
    dataSpecifica.tm_min = 0;            // Minuti: 0
    dataSpecifica.tm_sec = 0;            // Secondi: 0

    // Conversione in time_t
    tempoSpecifico = mktime(&dataSpecifica);

    if (tempoSpecifico == (time_t)-1)
    {
        printf("Errore nella conversione della data.\n");
        exit(EXIT_FAILURE);
    }

    // Stampa della data specifica
    printf("La data specifica è: %s", ctime(&tempoSpecifico));
}