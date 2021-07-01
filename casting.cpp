#include <iostream>
// #include "spdlog/spdlog.h"

int main () {
    std::cout << "================================ Time To Learn C++ ================================" << std::endl;
    struct S1 { int a; } s1;
    struct S2 { int a; private: int b; } s2; // not standard-layout
    union U { int a; double b; } u; u.b = 1;
    int array[2];
 
    int* p1 = reinterpret_cast<int*>(&s1);  // value of p1 is "pointer to s1.a" because s1.a
                                            // and s1 are pointer-interconvertible
 
    int* p2 = reinterpret_cast<int*>(&s2);  // value of p2 is unchanged by reinterpret_cast and
                                            // is "pointer to s2". 
 
    int* p3 = reinterpret_cast<int*>(&u);   // value of p3 is "pointer to u.a": u.a and u are
                                            // pointer-interconvertible
 
    double* p4 = reinterpret_cast<double*>(p3); // value of p4 is "pointer to u.b": u.a and u.b
                                                // are pointer-interconvertible because both
                                                // are pointer-interconvertible with u
 
    int* p5 = reinterpret_cast<int*>(&array);   // value of p5 is unchanged by reinterpret_cast and
                                                // is "pointer to arr"

    std::cout << "p1: " << *p1 << std::endl;
    std::cout << "p2: " << *p2 << std::endl;
    std::cout << "p3: " << *p3 << std::endl;
    std::cout << "p4: " << *p4 << std::endl;
    std::cout << "p5: " << *p5 << std::endl;
    std::cout << "================================ Time To Learn C++ ================================" << std::endl;
}