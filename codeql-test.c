#include <stdio.h>
#include <stdnoreturn.h>

_Noreturn void assert_no_return_c11(void) {
    puts("c11");
}

noreturn void assert_no_return_c11_std(void) {
    puts("c11 std");
}

__attribute__((__noreturn__)) void assert_no_return_c99(void) {
    puts("c99");
}

static int foo_c99(int x) {
    if (x == 42)
        return 0;

    assert_no_return_c99();
}

static int bar_c11(int x) {
    if (x == 42)
        return 0;

    assert_no_return_c11();
}

static int baz_c11_std(int x) {
    if (x == 42)
        return 0;

    assert_no_return_c11_std();
}

int main(void) {
    foo_c99(42);
    bar_c11(42);
    baz_c11_std(42);

    return 0;
}
