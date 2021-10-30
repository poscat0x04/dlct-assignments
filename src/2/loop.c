#include <stdio.h>

void print_sep(int n);

void print_ws(int n);

int main(void) {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    print_ws(n - i);
    print_sep(i);
  }
  for(int i = 1; i < n; i++) {
    print_ws(i);
    print_sep(n - i);
  }
}

void print_ws(int n) {
  for(int i = 0; i < n; i++) {
    printf(" ");
  }
}

void print_sep(int n) {
  for(int i = 0; i < n - 1; i++) {
    printf("%d ", n);
  }
  printf("%d\n", n);
}