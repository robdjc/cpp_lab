#include <cstdio>

struct SomeType {
    int data = 42;
};

void vexing_parse() {
    std::printf("vexing_parse\n");

    // warning: parentheses were disambiguated as a function declaration [-Wvexing-parse]
    // note: replace parentheses with braces to declare a variable
    // error: request for member ‘data’ in ‘st1’, which is of non-class type ‘SomeType()’

    // most vexing parse, won't compile
    // SomeType st1();
    // std::printf("%d\n", st1.data);

    // some ways to avoid the most vexing parse
    SomeType st2{};
    std::printf("%d\n", st2.data);

    SomeType st3{};
    std::printf("%d\n", st3.data);
}
