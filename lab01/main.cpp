#include <iostream>
#include <cmath>

// Функция для проверки, является ли число полным квадратом
bool is_perfect_square(int num) {
    int root = sqrt(num);
    return root * root == num;
}

// Функция для поиска ближайшей пары чисел
std::pair<int, int> closest_pair_tonum(int upper_limit) {
    for (int m = upper_limit - 1; m > 0; m--) {
        for (int n = m - 1; n > 0; n--) {
            if (is_perfect_square(m + n) && is_perfect_square(m - n)) {
                return {m, n};
            }
        }
    }
    return {0, 0}; // Если пара не найдена
}

int main() {
    int upper_limit;
    std::cout << "Введите верхнюю границу: ";
    std::cin >> upper_limit;
    
    auto result = closest_pair_tonum(upper_limit);
    std::cout << "Ближайшая пара: (" << result.first << ", " << result.second << ")" << std::endl;
    
    return 0;
}