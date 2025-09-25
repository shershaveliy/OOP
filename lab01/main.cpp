#include <iostream>
#include <cmath>

bool is_perfect_square(int x) {
    int root = sqrt(x);
    return root * root == x;
}

bool closest_pair_tonum(int v, int &m, int &n) {
    for (m = v - 1; m > 0; m--) {
        for (n = m - 1; n > 0; n--) {
            if (is_perfect_square(m + n) && is_perfect_square(m - n)) {
                return true;
            }
        }
    }
    m = 0;
    n = 0;
    return false;
}

int main() {
    int v, m, n;
    std::cout << "Введите верхнюю границу: ";
    std::cin >> v;
    if(v <= 0){
        std::cout << "Число должны быть положительным";
        return 1;
    }
    
    if (closest_pair_tonum(v, m, n)) {
        std::cout << "Ближайшая пара: (" << m << ", " << n << ")" << std::endl;
    }
    else std::cout << "Пара не найдена" << std::endl;
    
    return 0;
}