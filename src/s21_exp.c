/* Функция s21_exp(double x).
 * Возводит e в степень x.
 */

#include "s21_math.h"

long double s21_exp(double x) {
  long double expf = 1.000000;
  if (__builtin_isnan(x)) {
    expf = s21_NAN;
  } else if (x == -s21_INF) {
    expf = 0.000000;
  } else if (__builtin_isinf(x)) {
    expf = s21_INF;
  } else if (x == 0.0000000) {
    expf = 1.000000;
  } else {
    long double n = 1.0;
    long double p = 1.0;
    while (s21_fabs(p) > 1e-7) {
      p = p * x / n;
      n++;
      expf = expf + p;
      if (expf > DBL_MAX) {
        expf = s21_INF;
        break;
      }
    }
  }
  return expf;
}
