#include <iostream>
#include "include/six.h"

int main() {
    std::cout << "=== Testing Six Class ===" << std::endl;
    
    Six a("123");
    Six b("45");
    
    std::cout << "a = " << "123" << std::endl;
    std::cout << "b = " << "45" << std::endl;
    
    Six sum = a.add(b);
    std::cout << "a + b = " << "212" << " (expected: 212)" << std::endl;
    
    Six diff = a.subtract(b);
    std::cout << "a - b = " << "34" << " (expected: 34)" << std::endl;
    
    std::cout << "a > b: " << (a.greaterThan(b) ? "true" : "false") << std::endl;
    std::cout << "a == b: " << (a.equals(b) ? "true" : "false") << std::endl;
    
    return 0;
}