#include <clocale>
#include <cstdlib>
#include <iostream>
#include "menu.hpp"
#include "menu_functions.hpp"
#include "menuitems.hpp"

int main() {
    const sglt::MenuItem* current = &sglt::MAIN;
    while (true) {
        current = current->func(current);
    }
}
