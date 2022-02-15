#include <memory>
#include <stdio.h>
#include <assert.h>

struct A_t {
    uint64_t i = 0;
};

std::unique_ptr<A_t> createA(uint64_t i = 0) {
    return std::unique_ptr<A_t>(new A_t{i});
}

int main () {
    /*
    std::shared_ptr<A_t> sharedA;
    std::unique_ptr<A_t> uniqueA;
    if (sharedA == nullptr) {
        printf("'sharedA' is null\n");
    }
    if (uniqueA == nullptr) {
        printf("'uniqueA' is null\n");
    }
    */
    std::shared_ptr<A_t> sharedA = std::shared_ptr<A_t>(new A_t());
    std::unique_ptr<A_t> uniqueA = nullptr;
    assert(uniqueA == nullptr);
    uniqueA = std::make_unique<A_t>();
    std::unique_ptr<A_t>& refUniqueA = uniqueA;
    uniqueA->i = 99;
    printf("refUniqueA->i = %llu\n", refUniqueA->i);
    // std::unique_ptr<A_t> cpyUniqueA = uniqueA; // compile error: call to implicitly-deleted copy constructor of 'std::unique_ptr<A_t>'
    std::unique_ptr<A_t> anotherA = createA();
    const std::unique_ptr<A_t>& constRefUniqueA = uniqueA;
    constRefUniqueA->i = 100;
    printf("refUniqueA->i = %llu\n", refUniqueA->i);
    return 0;
}