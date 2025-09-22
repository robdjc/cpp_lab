
#include <cassert>
#include <cstdio>
#include <string>

void sizeof_string() {
    std::printf("sizeof_string\n");
    std::string s;
    std::printf("sizeof(std::string)=%zu\n", sizeof(std::string));
    assert(s.size() == 0);
    s = "abcdef";
    std::printf("after assign: size=%zu capacity=%zu\n", s.size(), s.capacity());
    assert(s.size() == 6);
    std::printf("\n");
}
