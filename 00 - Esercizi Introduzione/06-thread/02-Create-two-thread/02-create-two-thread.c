#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Problema: punta alla stessa variabile
void *my_thread(void *);

int main(int argc, char const *argv[])
{
  int pid = getpid();
  pthread_t thread_id_1, thread_id_2;
  int n = 42;
  printf("[%d] Ora provo a creare un thread.\n", pid);

  int rc = pthread_create(&thread_id_1, NULL, my_thread, (void *)&n);

  if (rc != 0)
  {
    printf("[%d] Errore nella creazione del thread 1.\n", pid);
    return -2;
  }
  n = 78;
  printf("[%d] Ora provo a creare un'altro thread.\n", pid);
  rc = pthread_create(&thread_id_2, NULL, my_thread, (void *)&n);

  if (rc != 0)
  {
    printf("[%d] Errore nella creazione del thread 2.\n", pid);
    return -2;
  }

  printf("[%d] Ora provo ad aspettare la fine del thread [%li].\n", pid, thread_id_1);
  pthread_join(thread_id_1, NULL);
  printf("[%d] Ora provo ad aspettare la fine del thread [%li].\n", pid, thread_id_2);
  pthread_join(thread_id_2, NULL);
  printf("[%d] Termine esecuzione.\n", pid);
  return 0;
}

void *my_thread(void *param)
{
  int *p_n = (int *)param;
  printf("\n[%li] Il mio parametro è: [%d]\n\n", pthread_self(), *p_n);
  return NULL;
}