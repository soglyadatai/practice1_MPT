#include <cmath>
#include <iostream>

int main() {
	double angle;
	std::cout << "Введите угол" << std::endl;
	std::cin >> angle;
	
	if  (cos(2 * angle) != 1) {
		double result = (1 + sin (2 * angle)) / (1 - cos(2 * angle));
		std::cout << "Значемние функции F(x1) = " << result << std::endl;
	} else if  (cos(2 * angle) == 1) {
		std::cout << "Неверное значение F(x1)" << std::endl;
	}
	
	if  (tan(angle) != 1) {
		double result = 
			(1 + tan(angle) * tan(angle)) 
			/ 
			(1 - tan(angle) * tan(angle));
		std::cout << "Значемние функции F(x2) = " << result << std::endl;
	} else if (tan((double)angle) == 1) {
		std::cout << "Неверное значение F(x2) " << std::endl;
	}

	return 0;
}
