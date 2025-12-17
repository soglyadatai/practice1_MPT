#pragma once

namespace sglt {
	struct MenuItem {
		const char* title;
		const MenuItem* (*func)(const MenuItem* current);

		const MenuItem* parent;

		const MenuItem* const* children;
		int children_count;
	};
}
