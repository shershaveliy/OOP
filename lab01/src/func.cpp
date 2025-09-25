#include "../include/func.h"
#include <cmath>

bool is_perfect_square(int x) {
    int root = sqrt(x);
    return root * root == x;
}

bool closest_pair_tonum(int v, int &m, int &n){
    for (m = v - 1; m > 0; m--) {
        for (n = m - 1; n > 0; n--){
            if (is_perfect_square(m + n) && is_perfect_square(m - n)){
                return true;
            }
        }
    }
    m = 0;
    n = 0;
    return false;
}