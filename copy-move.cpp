#include <iostream>
#include "myClasses.hpp"


int main () {
    std::cout << "================================ Time To Learn C++ ================================" << std::endl;
    A a0;
    A a1 = A();
    A a2(2, "A");
    A a3{3, "A"};
    A a4 = A(4, "A");
    A aa2 = a2;

    std::cout << "before move" << std::endl;
    std::cout << "** " << a3.ivalue << std::endl;
    std::cout << "** " << a3.svalue << std::endl;
    
    A aa3(std::move(a3));

    std::cout << "after move" << std::endl;
    std::cout << "** " << a3.ivalue << std::endl;
    std::cout << "** " << a3.svalue << std::endl;
    std::cout << "** " << aa3.ivalue << std::endl;
    std::cout << "** " << aa3.svalue << std::endl;
    
    A aa4;
    aa4 = std::move(a4);

    std::cout << "================================ Time To Learn C++ ================================" << std::endl;
}