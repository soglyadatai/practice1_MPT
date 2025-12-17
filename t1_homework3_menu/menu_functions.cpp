#include "menu_functions.hpp"

#include <iostream>
#include <cstdlib>

namespace {
	const sglt::MenuItem* show_menu(const sglt::MenuItem* current) {
		for (int i = 1; i < current->children_count; i++) {
			std::cout << current->children[i]->title << std::endl;
		}
		std::cout << current->children[0]->title << std::endl;
		std::cout << " Русские писатели > ";

		int user_input;
		std::cin >> user_input;
		std::cout << std::endl;

		return current->children[user_input];
	}
}

const sglt::MenuItem* sglt::show_main_menu(const MenuItem* current) {
	std::cout << "Главное меню:" << std::endl;
	return show_menu(current);
}

const sglt::MenuItem* sglt::show_second_menu(const MenuItem* current) {
	std::cout << "Второй уровень меню:" << std::endl;
	return show_menu(current);
}

const sglt::MenuItem* sglt::show_third_menu(const MenuItem* current) {
	std::cout << "Произведения Пушкина:" << std::endl;
	return show_menu(current);
}

const sglt::MenuItem* sglt::exit(const MenuItem*) {
	std::exit(0);
}

const sglt::MenuItem* sglt::read_text(const MenuItem* current) {
	std::cout << "Чтение: " << current->title << std::endl << std::endl;
	return current->parent;
}

const sglt::MenuItem* sglt::go_back(const MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent->parent;
}


int i1;
bool b1;
int i2;