#pragma once
#include "menu.hpp"

namespace sglt {
	const MenuItem* show_main_menu(const MenuItem* current);
	const MenuItem* show_second_menu(const MenuItem* current);
	const MenuItem* show_third_menu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);
	const MenuItem* read_text(const MenuItem* current);
	const MenuItem* go_back(const MenuItem* current);
}
