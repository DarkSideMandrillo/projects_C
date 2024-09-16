#include <stdio.h>
/*
FILE *fopen(const char *filename, const char *mode);
filename: è il nome del file che vuoi aprire.
mode: indica il modo in cui vuoi aprire il file. I principali modi sono:
"r": lettura (il file deve esistere).
"w": scrittura (se il file esiste, viene sovrascritto; altrimenti, viene creato).
"a": aggiunta in fondo al file (crea il file se non esiste).
"r+": lettura e scrittura (il file deve esistere).
"w+": lettura e scrittura (sovrascrive il file o lo crea).
"a+": lettura e scrittura (aggiunge i dati alla fine del file).
*/
int main()
{
  //  APERTURA FILE
  FILE *file = fopen("file.txt", "r+");
  if (file == NULL)
  {
    printf("Errore nell'apertura del file\n");
    return 1; // errore
  }

  // LETTURA

  //  fgetc() - legge un carattere
  char c = fgetc(file);
  printf("%c\n", c);

  //  fgets(char *str, int n, FILE *file): legge una riga di testo (fino a n-1 caratteri o fino a un carattere di nuova linea).
  char buffer1[100];
  fgets(buffer1, 100, file);
  printf("%s\n", buffer1);

  //  fread(void *ptr, size_t size, size_t count, FILE *file): legge blocchi di dati binari. È utile per leggere dati binari o array.
  char buffer2[11];
  fread(buffer2, sizeof(char), 10, file);
  buffer2[10] = '\0';
  printf("%s\n", buffer2);

  // SCRITTURA

  //  Riposizionare il puntatore del file all'inizio per scrivere
  fseek(file, 0, SEEK_END); // Sposta il puntatore alla fine del file

  //  fputc(int c, FILE *file): scrive un carattere nel file.
  fputc('A', file);

  // fputs(const char *str, FILE *file): scrive una stringa nel file.
  fputs("Ciao mondo\n", file);

  //  feof(FILE *file): verifica la fine del file.
  //  ferror(FILE *file): controlla se ci sono stati errori nel file.

  // Riposiziona il puntatore all'inizio del file prima di leggere di nuovo
  fseek(file, 0, SEEK_SET); // Sposta il puntatore all'inizio del file
  char buffer3[100];
  // Leggi ogni riga dal file fino a quando `fgets` restituisce NULL
  while (fgets(buffer3, sizeof(buffer3), file) != NULL)
  {
    printf("%s", buffer3); // Stampa la riga
  }

  // Chiude il file
  fclose(file);
  return 0;
}