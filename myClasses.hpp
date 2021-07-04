#include <string>
#include <utility>

class A {
public:
    int ivalue;
    std::string svalue;
    A() {
        std::cout << "Regular Default Constructor" << std::endl;
        ivalue = 0;
        svalue = "A";
    }

    A(int ivalue, std::string svalue) {
        std::cout << "Regular Constructor" << std::endl;
        this->ivalue = ivalue;
        this->svalue = svalue;
    }

    A(A& src) {
        std::cout << "Copy Constructor" << std::endl;
        this->ivalue = src.ivalue;
        this->svalue = src.svalue;
    }

    A(A&& src) : ivalue(std::exchange(src.ivalue, 0)), svalue(std::move(src.svalue)) {
        std::cout << "Move Constructor" << std::endl;
    }

    A& operator= (const A& rhs) {
        std::cout << "copy operator=" << std::endl;
        this->ivalue = rhs.ivalue;
        this->svalue = rhs.svalue;
        return *this;
    }

    A& operator= (A&& rhs) {
        std::cout << "move operator=" << std::endl;
        this->ivalue = std::exchange(rhs.ivalue, 0);
        this->svalue = std::move(rhs.svalue);
        return *this;
    }
};

class A_A : public A {
public:
    A_A() {
        ivalue = 1;
        svalue = "A_A";
    }
};

class A_B : public A {
public:
    A_B() {
        ivalue = 1;
        svalue = "A_B";
    }
};