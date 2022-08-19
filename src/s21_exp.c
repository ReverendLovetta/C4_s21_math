/* Функция s21_exp(double x).
 * Возводит e в степень x.
 */

#include "s21_math.h"

long double s21_exp(double x) {
  long double expf = 1.000000;
  if (x == s21_NAN) {
    expf = s21_NAN;
  } else if (x == +s21_INF) {
    expf = +s21_INF;
  } else if (x == -s21_INF) {
    expf = +0;
  } else if (x == 0) {
    expf = 1;
  } else {
    long double n = 1.0;
    long double p = 1.0;
    while (s21_fabs(p) > 1e-7) {
      p = p * x / n;
      n++;
      expf = expf + p;
      if (expf > DBL_MAX) {
        expf = s21_HUGE_VAL;
        break;
      }
      if (expf < -DBL_MAX) {
        expf = 0;
        break;
      }
    }
  }
  return expf;
}
