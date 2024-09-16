#include <pthread.h>
#include <stdio.h>

void *my_thread(void *);

int main(int argc, char const *argv[])
{
  pthread_t thread_id;

  printf("Ora provo a creare un thread...\n");

  int rc = pthread_create(&thread_id, NULL, my_thread, NULL);
  if (rc != 0)
  {
    printf("Errore nella creazione del thread 1\n");
    return -2;
  }

  printf("Thread creato. Attendo la loro terminazione...\n");

  // Attendere che il thread termini
  rc = pthread_join(thread_id, NULL);
  if (rc != 0)
  {
    printf("Errore nell'attendere il thread\n");
    return -3;
  }

  printf("Thread terminato.\n");
  printf("Termine esecuzione\n");

  return 0;
}

void *my_thread(void *param)
{
  printf("Questo è il mio thread: [%p]\n", pthread_self());
  return NULL;
}
