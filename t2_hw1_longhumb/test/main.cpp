#include <iostream>
#include <utility>
#include <stdexcept>
#include "long_number.hpp"

using ssY::LongNumber;

int main() {
    LongNumber a("123456789");
    LongNumber b("12345");

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << "a % b = " << a % b << std::endl;

    std::cout << std::endl;

    if (a > b) {
        std::cout << "a > b" << std::endl;
    }

    if (a != b) {
        std::cout << "a != b" << std::endl;
    }

    LongNumber copy = a;
    std::cout << "copy = " << copy << std::endl;

    LongNumber c;
    c = "777777777";
    std::cout << "c = " << c << std::endl;

    LongNumber moved = std::move(c);
    std::cout << "moved = " << moved << std::endl;

    LongNumber x("-987654321");
    LongNumber y("12345");

    std::cout << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;
    std::cout << "x % y = " << x % y << std::endl;

    std::cout << std::endl;

    try {
        LongNumber zero("0");
        std::cout << "a / zero = " << a / zero << std::endl;
    } catch (const std::runtime_error& error) {
        std::cout << "error: " << error.what() << std::endl;
    }

    return 0;
}