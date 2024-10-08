
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int matricola;
  float *voti; // è il puntatore di un array
  int numVoti;
} Studente;

void popolaStudenti(Studente array[], int dim);
void creaPopolaArray(int dim, Studente *alunno);
void stampaArrayStudenti(Studente array[], int dim);
void stampaArray(float *array, int dim);

int main()
{
  int numStudenti;
  printf("Quanti studenti vuoi inserire? ");
  scanf("%d", &numStudenti);

  Studente *studenti = (Studente *)malloc(numStudenti * sizeof(Studente)); // usiamo la malloc per non riempire la memoria, la HEAP non si riempe

  popolaStudenti(studenti, numStudenti);
  printf("\n");
  stampaArrayStudenti(studenti, numStudenti);

  for (size_t i = 0; i < numStudenti; i++)
    free(studenti->voti);

  free(studenti); // Manca la free dei voti
  return 0;
}
// popola l'array di studenti
void popolaStudenti(Studente array[], int dim)
{
  for (int i = 0; i < dim; i++)
  {
    printf("Inserisci matricola: ");
    scanf("%d", &array[i].matricola);
    printf("Inserisci numero dei voti: ");
    scanf("%d", &array[i].numVoti);

    creaPopolaArray(array[i].numVoti, &array[i]);
  }
}
// crea l'array in base alla dimensione passata e lo popola
void creaPopolaArray(int dim, Studente *alunno)
{
  alunno->voti = (float *)malloc(sizeof(float) * dim);

  for (int i = 0; i < dim; i++)
  {
    printf("Inserisci valutazione %d: ", i + 1);
    scanf("%f", &alunno->voti[i]);
  }
}
// stampa a video gli studenti inseriti
void stampaArrayStudenti(Studente array[], int dim)
{
  for (int i = 0; i < dim; i++)
  {
    printf("\nMatricola %d: %d\n", i + 1, array[i].matricola);
    printf("Valutazioni: ");
    stampaArray(array[i].voti, array[i].numVoti);
  }
}
// stampa un array
void stampaArray(float *array, int dim)
{
  for (int i = 0; i < dim; i++)
  {
    printf("%.2f ", array[i]);
  }
  printf("\n");
}
