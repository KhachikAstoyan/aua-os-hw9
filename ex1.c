#include <pthread.h>
#include <stdio.h>

void *run(void *arg) {
  pthread_t id = pthread_self();
  printf("Thread %lu is running\n", id);
  return NULL;
}

int main() {
  pthread_t t1, t2, t3;

  pthread_create(&t1, NULL, run, NULL);
  pthread_create(&t2, NULL, run, NULL);
  pthread_create(&t3, NULL, run, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  return 0;
}
