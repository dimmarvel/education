#ifndef _ARRAY_TESTS_H
#define _ARRAY_TESTS_H

#define CHECK(expr1, expr2)                       \
if((expr1) == (expr2)) printf("passed\n");        \
else printf("ERROR: %s == %s \n", #expr1, #expr2) \

#define CHECK_EXPR(expr1, bad_info)                     \
if(expr1) printf("passed\n");                           \
else printf("ERROR: %s, info: %s\n", #expr1, bad_info)  \

extern void test_removes();
extern void test_clear();
extern void test_compare();
extern void test_helpers_func();
extern void test_merge();
extern void test_algorithms();
extern void do_tests();

#endif /* _ARRAY_TESTS_H */
