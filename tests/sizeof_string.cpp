#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <cstddef>
#include <span>

bool data_inside_object(const std::string& s) {
    auto bytes = std::as_bytes(std::span{&s, 1}); // span<const std::byte> over s
    const void* dp = static_cast<const void*>(s.data());
    for (size_t i = 0; i < bytes.size(); ++i) {
        const void* bp = static_cast<const void*>(bytes.data() + i);
        if (bp == dp) return true;
    }
    return false;
}

std::vector<std::string> string_bytes(const std::string& s) {
    const auto* p = reinterpret_cast<const unsigned char*>(&s);
    const std::size_t n = sizeof(s);

    std::vector<std::string> out;
    out.reserve(n);

    char buf[32] = {};
    for (std::size_t i = 0; i < n; ++i) {
        std::snprintf(buf, sizeof(buf), "%p",
            static_cast<const void*>(p + i));
        out.emplace_back(buf);
    }
    return out;
}

void sizeof_string() {

    std::printf("sizeof_string\n");
    std::printf("Possibly: 16 (SSO buffer) + 8 (size) + 8 (capacity/flags) = 32 bytes");

    std::string s_empty;
    std::printf("s_empty=%s: sizeof=%zu, size=%zu capacity=%zu\n", 
        s_empty.c_str(), sizeof(s_empty), s_empty.size(), s_empty.capacity());

    std::string s = "a";
    std::printf("s=%s: sizeof=%zu, size=%zu capacity=%zu\n", 
        s.c_str(), sizeof(s), s.size(), s.capacity());

    // print the addresses of the string class
    auto addrs = string_bytes(s);
    for (const auto& addr_str : addrs) {
        std::printf("%s\n", addr_str.c_str());
    }

    const char* p_data = s.data();
    if (s.data() != p_data) {
        std::printf("s: started on the heap at size=%zu\n", s.size());
    }
    else {
        for (int i = 0; i < 30; ++i) {

            const char* p_tmp = s.data();
            std::printf("s=%s: sizeof=%zu, size=%zu, capacity=%zu, address=%p\n", 
                s.c_str(), sizeof(s), s.size(), s.capacity(), static_cast<const void*>(p_tmp));

            if (s.data() != p_data) {
                std::printf("s: pointer changed at size=%zu\n", s.size());
                break;
            }

            s.push_back('x');
        }
    }
}
