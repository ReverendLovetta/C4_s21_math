#include "../header.h"

START_TEST(test_s21_pow_00) {
    double x = 1.000000;
    double y = 1.000000;
    for (int i = 0; i < 2; i++) {
        ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
        x *= 1.500000;
        y *= 1.500000;
    }
}
END_TEST

START_TEST(test_s21_pow_01) {
    double x = 5.000000;
    double y = 1.000000;
    for (int i = 0; i < 2; i++) {
        ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
        x *= 1.500000;
        y += 1;
    }
}
END_TEST

START_TEST(test_s21_pow_02) {
    double x = -5.0;
    double y = 1.100000;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_08) {
    double x = -5.0;
    double y = 1.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_09) {
    double x = -5.0;
    double y = 2.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_10) {
    double x = -5.0;
    double y = -2.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_03) {
    double x = 5.000000;
    double y = 0.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_04) {
    double x = 0.000000;
    double y = 0.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_05) {
    double x = 0.000000;
    double y = -5.000000;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_06) {
    double x = s21_NAN;
    double y = -5.000000;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_07) {
    double x = 5.0;
    double y = s21_NAN;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_pow_00, *tc_s21_pow_01;
    s = suite_create("Math s21_pow");
    tc_s21_pow_00 = tcase_create("Check s21_pow_00");
    tcase_add_test(tc_s21_pow_00, test_s21_pow_00);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_01);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_08);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_09);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_10);
    suite_add_tcase(s, tc_s21_pow_00);  // Рандомные обычные значения
    tc_s21_pow_01 = tcase_create("Check s21_pow_01");
    tcase_add_test(tc_s21_pow_01, test_s21_pow_02);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_03);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_04);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_05);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_06);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_07);
    suite_add_tcase(s, tc_s21_pow_01);
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = math_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
