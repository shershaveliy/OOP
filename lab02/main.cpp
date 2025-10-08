#include <iostream>
#include "include/six.h"

int main() {
    
    Six a("123");
    Six b("45");
    
    std::cout << "a = ";
    a.print();
    std::cout << std::endl;
    
    std::cout << "b = ";
    b.print();
    std::cout << std::endl;
    
    Six sum = a.add(b);
    std::cout << "a + b = ";
    sum.print();
    std::cout << " (expected: 212)" << std::endl;
    
    Six diff = a.subtract(b);
    std::cout << "a - b = ";
    diff.print();
    std::cout << " (expected: 34)" << std::endl;
    
    std::cout << "a > b: " << (a.greaterThan(b) ? "true" : "false") << std::endl;
    std::cout << "a == b: " << (a.equals(b) ? "true" : "false") << std::endl;
    
    Six copy = a.copy();
    std::cout << "copy of a = ";
    copy.print();
    std::cout << std::endl;
    
    std::cout << "Test completed" << std::endl;
    
    return 0;
}