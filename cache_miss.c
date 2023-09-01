#include <stdlib.h>
#include <time.h>

// This program first creates an array of random integers. Then, it repeatedly
// accesses random elements in the array. Because the access pattern is random,
// the cache cannot effectively predict which elements will be accessed next,
// leading to a high number of cache misses.

#define ARRAY_SIZE 1000000
#define REPEAT 1000

int main() {
  int *array = malloc(ARRAY_SIZE * sizeof(int));
  srand(time(NULL));

  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }

  int sum = 0;
  for (int r = 0; r < REPEAT; r++) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
      sum += array[rand() % ARRAY_SIZE];
    }
  }

  free(array);
  return 0;
}
