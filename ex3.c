#include <pthread.h>
#include <stdio.h>

void *print_nums(void *arg) {
  pthread_t id = pthread_self();
  for (int i = 1; i <= 5; i++) {
    printf("Thread %lu: %d\n", id, i);
  }
  return NULL;
}

int main() {
  pthread_t t1, t2, t3;

  pthread_create(&t1, NULL, print_nums, NULL);
  pthread_create(&t2, NULL, print_nums, NULL);
  pthread_create(&t3, NULL, print_nums, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  return 0;
}
