#include <cstdio>


void unspecified() {
    std::printf("unspecififed\n");

    int i = 0;
    printf("i before..: %d\n", i);

    // in gcc it seems
    // Right i++ evaluated first → returns 0, then i becomes 1.
    // Left i++ evaluated next → returns 1, then i becomes 2.
    printf("i during..: %d %d\n", i++, i++);
    
    printf("i after...: %d\n", i);
}
