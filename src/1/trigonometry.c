#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point_t {
  long double x;
  long double y;
} point;

int compute_point(point b, point c, long double beta, long double gamma,
                  point *result);

bool is_valid_input(long double angle);

int main(void) {
  point res;
  point b, c;
  long double beta, gamma;

  scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &b.x, &b.y, &beta, &c.x, &c.y, &gamma);

  int r = compute_point(b, c, beta, gamma, &res);

  if (r == 0) {
    printf("(%Lf, %Lf)\n", res.x, res.y);
  } else if (r == -1) {
    printf("triangle does not exist\n");
  } else if (r == -2) {
    printf("invalid input\n");
    exit(1);
  } else {
    printf("unknown return value from compute_point: %d\n", r);
    exit(127);
  }
  return 0;
}

/**
 * @brief
 *
 * @param b
 * @param c
 * @param beta
 * @param gamma
 * @param result
 * @return int -1 means the triangle does not exist, -2 means invalid input, 0
 means the triangle exists and the point was written to the `result` pointer
 */
int compute_point(point b, point c, long double beta, long double gamma,
                  point *result) {
  if (is_valid_input(beta) && is_valid_input(gamma))

  {
    if (beta + gamma < M_PI) {
      // compute the angle between BC and the x axis
      long double alpha = atanl((c.y - b.y) / (c.x - b.x));
      // compute the slope of AB and AC
      long double k1 = tanl(alpha + beta);
      long double k2 = -tanl(gamma - alpha);
      // solve the linear equations
      long double c1 = b.y - k1 * b.x;
      long double c2 = c.y - k2 * c.x;
      long double det = k2 - k1;
      result->x = (c1 - c2) / det;
      result->y = (k2 * c1 - k1 * c2) / det;
      return 0;
    } else {
      return -1;
    }
  } else {
    return -2;
  }
}

bool is_valid_input(long double angle) { return angle > 0 && angle < M_PI; }