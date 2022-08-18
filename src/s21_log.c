#include "./s21_math.h"

long double s21_log(double x) {
    long double result = 0.000000;
    if (__builtin_isnan(x)) {
        result = s21_NAN;
    } else if (x == -s21_INF) {
        result = s21_NAN;
    } else if (__builtin_isinf(x)) {
        result = s21_INF;
    } else if (x == 0.000000) {
        result = s21_INF;
    } else if (x == 1.000000) {
        result = 0.000000;
    } else if (x < 0.0) {
        result = s21_NAN;
    } else {
        int p = 0;
        double cmp = 0.000000;
        for (; x > s21_E; p++) {
            x /= s21_E;
        }
        for (int i = 0; i < 100; i++) {
            cmp = result;
            result = cmp + 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));
        }
        result += p * 1.0;
    }
    return result;
}
