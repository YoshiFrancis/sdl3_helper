#ifndef SDL3HELPER_TEST_HPP
#define SDL3HELPER_TEST_HPP

#include <string_view>

namespace yoshi {
void load_texture(std::string_view file_path);
bool init(int w, int h);
} // namespace yoshi

#endif
