#include <cstdio>


void for_loop() {
    std::printf("for_loop\n");

    for (int i{}; i < 3; i++) {
        std::printf("i: %d\n", i);
    }

    for (int i{}; i < 3; ++i) {
        std::printf("i: %d\n", i);
    }

}
