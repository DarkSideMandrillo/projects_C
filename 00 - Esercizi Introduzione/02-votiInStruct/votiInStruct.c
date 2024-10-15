#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura
struct Student
{
  char name[20];
  int age;
  float *grades;
};

void newStudent(struct Student *studente);
void stampStudent(struct Student *student);

int main()
{
  struct Student student;
  newStudent(&student);
  stampStudent(&student);
  free(student.grades);

  return 0;
}

void newStudent(struct Student *student)
{
  int numberGrades = 0;
  printf("Inserisci nome dello studente: ");
  scanf("%s", student->name);
  printf("Inserisci età dello studente: ");
  scanf("%d", &((*student).age)); // instead of `&student->age`
  printf("Inserisci quanti voti ha preso lo studente: ");
  scanf("%d", &numberGrades);

  student->grades = (float *)malloc((numberGrades + 1) * sizeof(float));

  // Controllo se l'allocazione di memoria è avvenuta con successo
  if (student->grades == NULL)
  {
    printf("Errore nell'allocazione della memoria!\n");
    return;
  }

  // Inserimento dei voti
  for (size_t i = 0; i < numberGrades; i++)
  {
    printf("Inserisci il voto %d: ", i + 1);
    scanf("%f", &student->grades[i]);
  }

  // Aggiungi il valore sentinella alla fine
  student->grades[numberGrades] = -1.f;
}

void stampStudent(struct Student *student)
{
  size_t i = 0;
  while (student->grades[i] != -1.f)
  {
    printf("voto %d: %2.f\n", i + 1, student->grades[i]);
    i++;
  }
}
