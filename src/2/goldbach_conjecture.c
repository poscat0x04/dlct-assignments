#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct solution_t {
  uint64_t first;
  uint64_t second;
} * solution;

solution goldbach(uint64_t n);

int main(void) {
  uint64_t n;
  scanf("%lu", &n);
  solution solution = goldbach(n);
  if (solution != NULL) {
    printf("%lu = %lu + %lu", n, solution->first, solution->second);
  } else {
    exit(1);
  }
}

solution goldbach(uint64_t n) {
  bool sieve[n + 1];
  for (uint64_t i = 0; i <= n; i++) {
    sieve[i] = true;
  }
  for (uint64_t i = 2; i <= n; i++) {
    if (sieve[i]) {
      for (uint64_t j = 2; i * j <= n; j++) {
        sieve[i * j] = false;
      }
    }
  }
  for (uint64_t i = 2; i <= n; i++) {
    if (sieve[i] && sieve[n - i]) {
      solution solution = malloc(16);
      solution->first = i;
      solution->second = n - i;
      return solution;
    }
  }
  return NULL;
}
