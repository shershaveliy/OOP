#include <iostream>
#include <cmath>
#include "include/func.h"


int main() {
    int v, m, n;
    std::cout << "Введите верхнюю границу: ";
    std::cin >> v;
    if(v <= 0){
        std::cout << "Число должны быть положительным" << std::endl;
        return 1;
    }
    
    if (closest_pair_tonum(v, m, n)) {
        std::cout << "Ближайшая пара: (" << m << ", " << n << ")" << std::endl;
    }
    else std::cout << "Пара не найдена" << std::endl;
    
    return 0;
}