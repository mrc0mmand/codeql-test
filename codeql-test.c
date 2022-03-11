#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__)) void assert_no_return_c99(void) {
    abort();
}

_Noreturn void assert_no_return_c11(void) {
    abort();
}

int foo(int x) {
    if (x > 10)
        return 42;

    assert_no_return_c99();
}

int bar(int x) {
    if (x > 10)
        return 42;

    assert_no_return_c11();
}

int main(void) {
    foo(99);
    bar(99);

    return 0;
}
