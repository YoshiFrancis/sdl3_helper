#include "test.hpp"

#include <string>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main() {
    init(WIDTH, HEIGHT);
    std::string png = "files/BananaSplit.png";
    renderTexture(png);
    return 0;
}
