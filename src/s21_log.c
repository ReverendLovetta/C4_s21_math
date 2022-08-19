#include "./s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if ((x == s21_NAN) || (x == s21_INF)) {
    result = x;
  } else if (x == 1) {
    result = +0;
  } else if (x == 0) {
    result = -s21_HUGE_VAL;
  } else if (x < -0) {
    result = s21_NAN;
  } else {
    int p = 0;
    double cmp = 0;
    for (; x >= s21_E; p++) {
      x /= s21_E;
    }
    for (int i = 0; i < 100; i++) {
      cmp = result;
      result = cmp + 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));
    }
    result += p;
  }
  return result;
}
