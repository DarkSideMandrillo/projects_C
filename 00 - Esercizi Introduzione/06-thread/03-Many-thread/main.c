#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void *my_thread(void *);

int main(int argc, char const *argv[])
{
  printf("Inserisci il numero di thread da creare: ");
  int n = 0;
  scanf("%i", &n);
  // if (argc != 2) // se è diverso da 2 (1 nome programma, 2 numero di thread) esce con errore
  // {
  //   printf("USAGE: %s NUM_THREADS\n", argv[0]);
  //   return -1;
  // }

  // int n = atoi(argv[1]); // converte stringa di caratteri in intero
  int pid = getpid();
  printf("[%d] Ora creo %d thread.\n", pid, n);
  pthread_t *thread_id = (pthread_t *)malloc(sizeof(pthread_t) * n);


  //  Aggiungendo i, il compilatore capisce che vuoi saltare i elementi del tipo pthread_t, non i byte. Per esempio, se i è 1, il puntatore salta di sizeof(pthread_t) bytes (che può essere 4 o 8 bytes, a seconda della piattaforma).
  for (int i = 0; i < n; i++)
  {
    int rc = pthread_create(thread_id + i, NULL, my_thread, (void *)&i);
    if (rc != 0)
    {
      printf("[%d] Errore nella creazione del thread %d.\n", pid, i);
      return -2;
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("[%d] Ora aspetto la fine del thread [%li].\n",
           pid, *(thread_id + i));
    pthread_join(*(thread_id + i), NULL);
  }
  free(thread_id);
  printf("[%d] Termine esecuzione.\n", pid);
  return 0;
}
void *my_thread(void *param)
{
  int *p_n = (int *)param;
  printf("\n[%li] Il mio parametro è: [%d]\n\n", pthread_self(), *p_n);
  return NULL;
}