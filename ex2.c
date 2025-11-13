#include <pthread.h>
#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6};

void *sum_half(void *arg) {
  int start = ((int *)arg)[0];
  int end = ((int *)arg)[1];

  int sum = 0;
  for (int i = start; i < end; i++)
    sum += arr[i];

  printf("Partial sum: %d\n", sum);
  return NULL;
}

int main() {
  pthread_t t1, t2;
  int result1 = 0, result2 = 0;

  int args1[3] = {0, 3};
  int args2[3] = {3, 6};

  pthread_create(&t1, NULL, sum_half, args1);
  pthread_create(&t2, NULL, sum_half, args2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
