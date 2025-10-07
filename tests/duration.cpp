#include <cstdio>

// Static storage duration - zero-initialized
// Automatic storage duration - Not initialized unless you do it
// Thread storage duration - zero-initialized like static
// Dynamic storage duration - new/delete

int i;

void duration() {
    std::printf("duration\n");

    std::printf("static duration: %d\n", i);

    int j; 
    std::printf("automatic storage duration: %d\n", j);
}
