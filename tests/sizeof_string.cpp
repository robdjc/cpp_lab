#include <cstdio>
#include <string>

void sizeof_string() {
    std::printf("sizeof_string\n");
    std::printf("Posibly: 16 (SSO buffer) + 8 (size) + 8 (capacity/flags) = 32 bytes");
    
    std::string s_empty;
    std::printf("s_empty=%s: sizeof=%zu, size=%zu capacity=%zu\n", 
        s_empty.c_str(), sizeof(s_empty), s_empty.size(), s_empty.capacity());

    std::string s = "a";
    std::printf("s=%s: sizeof=%zu, size=%zu capacity=%zu\n", 
        s.c_str(), sizeof(s), s.size(), s.capacity());

    const char* p_data = s.data();
    if (s.data() != p_data) {
        std::printf("s: started on the heap at size=%zu\n", s.size());
    }
    else {
        for (int i = 0; i < 100; ++i) {
            s.push_back('x');

            std::printf("s=%s: sizeof=%zu, size=%zu capacity=%zu\n", 
                s.c_str(), sizeof(s), s.size(), s.capacity());

            if (s.data() != p_data) {
                std::printf("s: pointer changed at size=%zu\n", s.size());
                break;
            }
        }
    }
}
