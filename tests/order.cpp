#include <cstdio>

class A {
public:
    A() {std::printf("A::ctor\n"); }
    ~A() {std::printf("A::dtor\n"); }
};

class B {
public:
    B() {std::printf("B::ctor\n"); }
    ~B() {std::printf("B::dtor\n"); }
};

class C {
public:
    C() {std::printf("C::ctor\n"); }
    ~C() {std::printf("C::dtor\n"); }
};

void order() {
    std::printf("order\n");
    B b;
    A a;
    C c;
}
