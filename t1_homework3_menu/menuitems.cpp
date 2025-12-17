#include "menuitems.hpp"

#include <cstddef>
#include "menu_functions.hpp"

const sglt::MenuItem sglt::DUBROVSKY = {
	"1 — Дубровский", sglt::read_text, &sglt::PUSHKIN
};

const sglt::MenuItem sglt::ONEGIN = {
	"2 — Евгений Онегин", sglt::read_text, &sglt::PUSHKIN
};

const sglt::MenuItem sglt::WINTER = {
	"3 — Зимний вечер", sglt::read_text, &sglt::PUSHKIN
};

const sglt::MenuItem sglt::PUSHKIN_GO_BACK = {
	"0 — Выйти в предыдущее меню", sglt::go_back, &sglt::PUSHKIN
};

namespace {
	const sglt::MenuItem* const pushkin_children[] = {
		&sglt::PUSHKIN_GO_BACK,
		&sglt::DUBROVSKY,
		&sglt::ONEGIN,
		&sglt::WINTER
	};
	const int pushkin_size =
		sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}

const sglt::MenuItem sglt::PUSHKIN = {
	"1 — Читать Пушкина",
	sglt::show_third_menu,
	&sglt::WRITERS,
	pushkin_children,
	pushkin_size
};

const sglt::MenuItem sglt::LERMONTOV = {
	"2 — Читать Лермонтова", sglt::read_text, &sglt::WRITERS
};

const sglt::MenuItem sglt::KRYLOV = {
	"3 — Читать Крылова", sglt::read_text, &sglt::WRITERS
};

const sglt::MenuItem sglt::WRITERS_GO_BACK = {
	"0 — Выйти в главное меню", sglt::go_back, &sglt::WRITERS
};

namespace {
	const sglt::MenuItem* const writers_children[] = {
		&sglt::WRITERS_GO_BACK,
		&sglt::PUSHKIN,
		&sglt::LERMONTOV,
		&sglt::KRYLOV
	};
	const int writers_size =
		sizeof(writers_children) / sizeof(writers_children[0]);
}


const sglt::MenuItem sglt::WRITERS = {
	"1 — Русские писатели",
	sglt::show_second_menu,
	&sglt::MAIN,
	writers_children,
	writers_size
};

const sglt::MenuItem sglt::EXIT = {
	"0 — Завершить чтение", sglt::exit, &sglt::MAIN
};

namespace {
	const sglt::MenuItem* const main_children[] = {
		&sglt::EXIT,
		&sglt::WRITERS
	};
	const int main_size =
		sizeof(main_children) / sizeof(main_children[0]);
}

const sglt::MenuItem sglt::MAIN = {
	nullptr, sglt::show_main_menu, nullptr, main_children, main_size
};

const sglt::MenuItem sglt::MAIN_MENU = {
	nullptr, sglt::show_main_menu, nullptr, main_children, main_size
};

const sglt::MenuItem sglt::SECOND_MENU = {
	nullptr, sglt::show_second_menu, nullptr, main_children, main_size
};

const sglt::MenuItem sglt::THIRD_MENU = {
	nullptr, sglt::show_third_menu, nullptr, main_children, main_size
};
