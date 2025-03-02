#include <check.h>
#include "mm_vector.h"
#include <stdlib.h>

START_TEST(test_mm_vector_init)
{
    mm_vector_t vec;
    uint8_t buffer[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer, sizeof(buffer) / sizeof(int)));
    ck_assert_int_eq(mm_vector_size(&vec), 0);
    ck_assert_int_eq(mm_vector_capacity(&vec), 256 / sizeof(int));
}
END_TEST

START_TEST(test_mm_vector_push_pop)
{
    mm_vector_t vec;
    uint8_t buffer[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer, sizeof(buffer) / sizeof(int)));

    int data[] = {1, 2, 3};
    ck_assert(mm_vector_push(&vec, data, 3));
    ck_assert_int_eq(mm_vector_size(&vec), 3);

    int popped_data[3];
    ck_assert_int_eq(mm_vector_pop(&vec, popped_data, 3), 3);
    ck_assert_int_eq(popped_data[0], 1);
    ck_assert_int_eq(popped_data[1], 2);
    ck_assert_int_eq(popped_data[2], 3);
    ck_assert_int_eq(mm_vector_size(&vec), 0);
}
END_TEST

START_TEST(test_mm_vector_insert_delete)
{
    mm_vector_t vec;
    uint8_t buffer[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer, sizeof(buffer) / sizeof(int)));

    int data[] = {1, 2, 3};
    ck_assert(mm_vector_push(&vec, data, 3));

    int insert_data[] = {4, 5};
    ck_assert(mm_vector_insert(&vec, 1, insert_data, 2));
    ck_assert_int_eq(mm_vector_size(&vec), 5);

    int deleted_data[2];
    ck_assert(mm_vector_delete(&vec, 1, deleted_data, 2));
    ck_assert_int_eq(deleted_data[0], 4);
    ck_assert_int_eq(deleted_data[1], 5);
    ck_assert_int_eq(mm_vector_size(&vec), 3);
}
END_TEST

START_TEST(test_mm_vector_set_get)
{
    mm_vector_t vec;
    uint8_t buffer[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer, sizeof(buffer) / sizeof(int)));

    int data[] = {1, 2, 3};
    ck_assert(mm_vector_push(&vec, data, 3));

    int new_value = 10;
    ck_assert(mm_vector_set(&vec, 1, &new_value, 1));

    int value;
    ck_assert(mm_vector_get(&vec, 1, &value, 1));
    ck_assert_int_eq(value, 10);
}
END_TEST

START_TEST(test_mm_vector_clear)
{
    mm_vector_t vec;
    uint8_t buffer[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer, sizeof(buffer) / sizeof(int)));

    int data[] = {1, 2, 3};
    ck_assert(mm_vector_push(&vec, data, 3));

    mm_vector_clear(&vec);
    ck_assert(mm_vector_is_empty(&vec));
}
END_TEST

START_TEST(test_mm_vector_resize_swap)
{
    mm_vector_t vec, vec2;
    uint8_t buffer1[256], buffer2[256];
    ck_assert(mm_vector_init(&vec, sizeof(int), buffer1, sizeof(buffer1) / sizeof(int)));
    ck_assert(mm_vector_init(&vec2, sizeof(int), buffer2, sizeof(buffer2) / sizeof(int)));

    int data[] = {1, 2, 3};
    ck_assert(mm_vector_push(&vec, data, 3));

    ck_assert(mm_vector_resize(&vec, 2));
    ck_assert_int_eq(mm_vector_size(&vec), 2);

    ck_assert(mm_vector_swap(&vec, &vec2));
    ck_assert_int_eq(mm_vector_size(&vec2), 2);
    ck_assert_int_eq(mm_vector_size(&vec), 0);
}
END_TEST

Suite *mm_vector_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("MM Vector");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_mm_vector_init);
    tcase_add_test(tc_core, test_mm_vector_push_pop);
    tcase_add_test(tc_core, test_mm_vector_insert_delete);
    tcase_add_test(tc_core, test_mm_vector_set_get);
    tcase_add_test(tc_core, test_mm_vector_clear);
    tcase_add_test(tc_core, test_mm_vector_resize_swap);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s  = mm_vector_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
