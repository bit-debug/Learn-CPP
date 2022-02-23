#include <stdio.h>
#include <stdint.h>
#include <type_traits>
#include <typeinfo>

#define isPowerOf2(number) ((number & (number - 1)) == 0)

struct A {
    uint32_t i = 0;
    A operator+(uint64_t& rhs) {
        return {0};
    }

    A operator+(uint64_t&& rhs) {
        return {0};
    }

    A operator-(uint64_t& rhs) {
        return {0};
    }

    A operator-(uint64_t&& rhs) {
        return {0};
    }
} a;

template <uint64_t multiple, typename T, class = typename std::enable_if_t<std::is_integral<T>::value>, class = typename std::enable_if_t<(multiple!=0) && isPowerOf2(multiple)>>
inline T
roundUp(T value)
{
    return (value + multiple - 1ULL);
}

int main () {
    bool rc;

    rc = isPowerOf2(2);
    printf("rc is %s.\n", rc ? "true" : "false");
    
    rc = isPowerOf2(3);
    printf("rc is %s.\n", rc ? "true" : "false");

    int n = -5;
    printf("~n = %d\n", ~n);

    uint64_t i = 63;
    auto b = a + i;
    auto c = a + 63ULL;

    auto d = roundUp<2>(i);
    // auto d = roundUp<2>(a);
}