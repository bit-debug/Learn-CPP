#include <stdio.h>

class NoCopy
{
public:
    NoCopy() = default;
    NoCopy(NoCopy&&) = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
    NoCopy& operator=(NoCopy&&) = default;
};

class NoMove
{
public:
    NoMove() = default;
    NoMove(NoMove&&) = delete;
    NoMove(const NoMove&) = default;
    NoMove& operator=(const NoMove&) = default;
    NoMove& operator=(NoMove&&) = delete;
};

class ptrByMove : public NoCopy {

};

class ptrByCopy : public NoMove {

};


int main () {
    return 0;
}