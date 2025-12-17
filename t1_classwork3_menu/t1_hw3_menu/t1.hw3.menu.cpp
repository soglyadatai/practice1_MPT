#include <iostream>
#include <string>
#include <locale>

void BookMenu() {
    int n;
    while (true) {
        std::cout << "---Произведения Пушкина---\n";
        std::cout << "1 -- Дубровский\n";
        std::cout << "2 -- Евгений Онегин\n";
        std::cout << "3 -- Зимний Вечер\n";
        std::cout << "0 -- Выйти в предыдущее меню\n";
        std::cin >> n;

        if (n == 1) std::cout << "Открывается: Дубровский\n";
        else if (n == 2) std::cout << "Открывается: Евгений Онегин\n";
        else if (n == 3) std::cout << "Открывается: Зимний Вечер\n";
        else if (n == 0) return;
        else std::cout << "error\n";
    }
}

void NameMenu() {
    int n;
    while (true) {
        std::cout << "--- Русские писатели ---\n";
        std::cout << "1 -- Читать Пушкина\n";
        std::cout << "2 -- Читать Лермонтова\n";
        std::cout << "3 -- Читать Крылова\n";
        std::cout << "0 -- Выйти в главное меню\n";
        std::cin >> n;

        if (n == 1) BookMenu();
        else if (n == 2) std::cout << "error\n";
        else if (n == 3) std::cout << "error\n";
        else if (n == 0) return;
        else std::cout << "error\n";
    }
}

void MainMenu() {
    int n;
    while (true) {
        std::cout << "--- Главное меню ---\n";
        std::cout << "1 -- Русские писатели\n";
        std::cout << "0 -- Завершить чтение\n";
        std::cin >> n;

        if (n == 1) NameMenu();
        else if (n == 0) {
            std::cout << "Выход...\n";
            return;
        }
        else std::cout << "error\n";
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    MainMenu();
    return 0;
}