#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year);

int main(void) {
  int year;
  scanf("%d", &year);
  if (is_leap_year(year))
    printf("Y\n");
  else
    printf("N\n");
}

bool is_leap_year(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
}
