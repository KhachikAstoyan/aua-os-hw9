#include <pthread.h>
#include <stdio.h>

int nums[] = {1, 2, 3, 4, 5};

void *square(void *arg) {
  int n = *(int *)arg;
  printf("Square of %d is %d\n", n, n * n);
  return NULL;
}

int main() {
  pthread_t threads[5];

  for (int i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, square, &nums[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
