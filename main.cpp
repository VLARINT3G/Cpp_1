#include <iostream>
#include <vector>
#include <algorithm> // для std::sort
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time
#include "BinarySearch.h"

int main() {
    std::srand(std::time(0)); // инициализация генератора случайных чисел

    int n = 10; // длина вектора
    std::vector<int> main_arr(n);
    for (int i = 0; i < n; ++i) {
        main_arr[i] = std::rand() % 100; // случайные числа в диапазоне от 0 до 99
    }

    // Вывод случайного вектора длиной 10
    std::cout << "Original vector: ";
    for (int i = 0; i < main_arr.size(); ++i) {
        std::cout << main_arr[i] << " ";
    }
    std::cout << std::endl;

    // Сортировка вектора
    std::sort(main_arr.begin(), main_arr.end());

    // Печать отсортированного вектора
    std::cout << "Sorted vector: ";
    for (int i = 0; i < main_arr.size(); ++i) {
        std::cout << main_arr[i] << " ";
    }
    std::cout << std::endl;

    // Значение для поиска
    int user_target;
    std::cout << "Type down a digit for search: ";
    std::cin >> user_target;

    // Создаем объект класса BinarySearch и выполняем поиск
    BinarySearch binary_search(main_arr);
    int result = binary_search.search(user_target);

    if (result < main_arr.size() && main_arr[result] == user_target) {
        std::cout << "Your element is in " << result + 1 << "-th place" << std::endl;
    } else {
        std::cout << "Your element is not found. It could be placed at position " << result + 1 << std::endl;
    }

    return 0;
}