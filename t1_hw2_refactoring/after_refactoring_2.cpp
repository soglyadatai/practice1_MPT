#include <cmath>
#include <iostream>

int main()
{
	const int size = 10;
    int arr[size];

    std::cout << "Ввод данных" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Введите целое значение элемента " << i << ": ";
        std::cin >> arr[i];
    }

	bool increasung = true;
    for(int i = 0; i < size - 1, i++) {
        if (arr[i] > arr[i + 1]){
            increasung = false;
			break;
        }
        i = i + 1;
    }

    if (!increasung) {
        std::cout << "Последовательность возрастающая" << std::endl;
    } else {
        std::cout << "Последовательность не возрастает" << std::endl;
    }

    return 0;
}
