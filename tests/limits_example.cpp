#include <cstdio>
#include <limits>

void limits_example() {
    std::printf("limits_example\n");

    std::printf("int min=%d max=%d\n", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::printf("double epsilon=%g\n", std::numeric_limits<double>::epsilon());
}
