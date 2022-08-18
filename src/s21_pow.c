/* Функция s21_pow(double base, double exp).
 *
 */

#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double result = 0.0;
    if (__builtin_isnan(base) || __builtin_isnan(exp)) {
        result = s21_NAN;
    } else if (base != 0.0 && exp == 0.0) {
        result = 1.0;
    } else if (base == 0.0 && exp == 0.0) {
        result = 1.0;
    } else if (base == 0.0 && exp < 0.0) {
        result = s21_INF;
    } else {
        if (base < 0.0) {
            if (exp != s21_ceil(exp)) {
                result = s21_NAN;
            } else {
                base = base * -1;
                result = s21_exp(exp * s21_log(base));
                if ((long long int)exp % 2 != 0) {
                    result *= -1;
                }
            }
        } else {
            result = s21_exp(exp * s21_log(base));
        }
    }
    return result;
}
