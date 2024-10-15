#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum per identificare i tipi di dati
// typedef enum
// {
//   TYPE_INT,
//   TYPE_FLOAT,
//   TYPE_STRING
// } DataType;

enum DataType
{
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_STRING
};

// Struttura per passare i dati e il tipo
// typedef struct
// {
//   void *data;
//   DataType type;
// } Data;

struct Data
{
  void *data;
  enum DataType type;
};

// Funzione che elabora i dati in base al tipo e restituisce un nuovo puntatore
void *process_data(struct Data *param);

int main()
{
  int num = 42;
  float fnum = 3.14;
  char str[50] = "Original";

  struct Data data1 = {&num, TYPE_INT}; // al posto di TYPE potrei mettere 0
  struct Data data2 = {&fnum, TYPE_FLOAT};
  struct Data data3 = {str, TYPE_STRING};

  int *result_int = (int *)process_data((void *)&data1); // devo fare un casting per trasformare il *void result in un puntatore di tipo corretto
  float *result_float = (float *)process_data(&data2);
  char *result_str = (char *)process_data(&data3);

  printf("Valore int modificato: %d\n", *result_int);
  printf("Valore float modificato: %.2f\n", *result_float);
  printf("Stringa modificata: %s\n", result_str);

  // Libera la memoria allocata
  free(result_int);
  free(result_float);
  free(result_str);

  return 0;
}

// Funzione che elabora i dati in base al tipo e restituisce un nuovo puntatore
void *process_data(struct Data *param)
{
  void *result = NULL;

  switch (param->type)
  {
  case TYPE_INT:
  {
    int *p = (int *)param->data;
    int *new_int = malloc(sizeof(int)); // se non faccio una malloc *new_int viene distrutto fuori dallo scope dello switch
    *new_int = *p + 10;
    result = new_int;
    break;
  }
  case TYPE_FLOAT:
  {
    float *p = (float *)param->data;
    float *new_float = malloc(sizeof(float));
    *new_float = *p + 1.5;
    result = new_float;
    break;
  }
  case TYPE_STRING:
  {
    char *p = (char *)param->data;
    char *new_str = malloc(strlen(p) + strlen(" modified") + 1);
    strcpy(new_str, p);
    strcat(new_str, " modified");
    result = new_str;
    break;
  }
  default:
    printf("Tipo non riconosciuto.\n");
    break;
  }

  return result;
}
