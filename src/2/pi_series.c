#include <math.h>
#include <stdio.h>

double calcPi(double);

int main(void) {
  double precision;
  scanf("%lf", &precision);
  printf("%.15f", calcPi(precision));
  return 0;
}

double calcPi(double precision) {
  double pi = 0;
  for (int i = 0; M_PI - pi > precision; i++) {
    pi += 1 / pow(16, i) *
          (4.0 / (8 * i + 1) - 2.0 / (8 * i + 4) - 1.0 / (8 * i + 5) -
           1.0 / (8 * i + 6));
  }
  return pi;
}
