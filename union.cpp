#include <stdio.h>
#include <stdint.h>
#include <algorithm>

struct A {
    A() = default;
    A(int a) : a(a) {}
    int a;
};

struct B {
    B() = default;
    int b;
};

struct C {
    int x = 0;
    union {
        A a;
        B b;
    };
};

struct D {
    int x = 0;
    union {
        uint64_t d1;
        double d2;
    };
};

struct E {
    int x = 0;
    union {
        unsigned char container[std::max(sizeof(A), sizeof(B))];
        A a;
        B b;
    };
};

int main () {
    C c = {1, A()}; // no default constructor
    D d;
    E e;

    return 0;
}