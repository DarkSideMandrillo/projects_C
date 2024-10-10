#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

typedef struct
{
    char name[MAX_NAME];
    int serialNumber;
    float *grades;
    int numGrades;
} Student;

int main(){

    int studentsNumber;
    printf("Quanti studenti vuoi inserire?\n");
    scanf("%d",&studentsNumber);

    Student *students = (Student*) malloc(studentsNumber * sizeof(Student));
    

    for (size_t i = 0; i < studentsNumber; i++)
    {
        // Nome
        printf("Inserisci il nome dello studente %d?\n",(i+1));
        scanf("%99s",students[i].name);
        // Matricola
        printf("Inserisci la matricola dello studente %d?\n",(i+1));
        scanf("%d",&students[i].serialNumber);
        // Numero di voti
        printf("Quanti voti ha?\n");
        scanf("%d",&students[i].numGrades);
        // Creo l'array per tenere i voti
        students[i].grades = (float*)malloc(students[i].numGrades*sizeof(float));
        for (size_t j = 0; j < students[i].numGrades; j++)
        {
            printf("Inserisci il voto %d: ",(j+1));
            scanf("%f",&students[i].grades[j]);
        }
        
    }

    // Stampo gli studenti
    printf("\nElenco degli studenti:\n");
    for (size_t i = 0; i < studentsNumber; i++)
    {
        printf("Nome: %s\n",students[i].name);
        printf("Matricola: %d\n",students[i].serialNumber);
        printf("Elenco voti: ");
        for (size_t j = 0; j < students[i].numGrades; j++)
        {
            printf(" %.2f |",students[i].grades[j]);
        }
        printf("\n");
    }
    
    
    for (size_t i = 0; i < studentsNumber; i++)
        free(students[i].grades);
    
    free(students);

    return 0;
}
