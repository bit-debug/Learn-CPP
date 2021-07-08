#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int number) : number_(number) {}
    void print_add(int i) const { std::cout << number_+i << '\n'; }
    int number_;
};
 
void print_number(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNumber {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_number;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_number(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_number, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_number = &Foo::number_;
    std::cout << "number_: " << f_number(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_object = PrintNumber();
    f_display_object(18);
 
    auto factorial = [](int n) {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        std::function<int(int)> f = [&](int n){ return (n < 2) ? 1 : n*f(n-1); };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return f(n);
    };
    for (int i{5}; i != 8; ++i) { std::cout << i << "! = " << factorial(i) << ";  "; }
    std::cout << std::endl;
}