#include "../include/six.h"
#include <algorithm>
#include <stdexcept>

Six::Six() : digits{0} {}

Six::Six(const size_t& n, unsigned char t) {
    if (n == 0) throw std::invalid_argument("Size cannot be zero");
    if (t >= 6) throw std::invalid_argument("Digit must be 0-5");
    digits = std::vector<unsigned char>(n, t);
}

Six::Six(const std::initializer_list<unsigned char>& t) {
    if (t.size() == 0) {
        digits = {0};
        return;
    }
    for (unsigned char digit : t) {
        if (digit >= 6) throw std::invalid_argument("Digit must be 0-5");
        digits.push_back(digit);
    }
    std::reverse(digits.begin(), digits.end());
}

Six::Six(const std::string& t) {
    if (t.empty()) throw std::invalid_argument("String cannot be empty");
    for (char c : t) {
        if (c < '0' || c > '5') throw std::invalid_argument("Invalid digit");
        digits.push_back(c - '0');
    }
    std::reverse(digits.begin(), digits.end());
}

Six::Six(const Six& other) : digits(other.digits) {}

Six::Six(Six&& other) noexcept : digits(std::move(other.digits)) {
    other.digits = {0};
}

Six::~Six() noexcept {}

Six Six::add(const Six& other) const {
    Six result;
    result.digits.clear();
    
    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        carry = sum / 6;
        result.digits.push_back(sum % 6);
    }
    
    return result;
}

Six Six::subtract(const Six& other) const {
    if (this->lessThan(other)) throw std::invalid_argument("Cannot subtract larger number");
    
    Six result;
    result.digits.clear();
    unsigned char borrow = 0;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        int current = digits[i] - borrow;
        int subtrahend = i < other.digits.size() ? other.digits[i] : 0;
        
        if (current < subtrahend) {
            current += 6;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits.push_back(current - subtrahend);
    }
    
    while (result.digits.size() > 1 && result.digits.back() == 0) {
        result.digits.pop_back();
    }
    
    return result;
}

Six Six::copy() const {
    return Six(*this);
}

Six Six::addAssign(const Six& other) const {
    return this->add(other);
}

Six Six::subtractAssign(const Six& other) const {
    return this->subtract(other);
}

bool Six::equals(const Six& other) const {
    return digits == other.digits;
}

bool Six::greaterThan(const Six& other) const {
    if (digits.size() != other.digits.size()) 
        return digits.size() > other.digits.size();
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) 
            return digits[i] > other.digits[i];
    }
    return false;
}

bool Six::lessThan(const Six& other) const {
    if (digits.size() != other.digits.size()) 
        return digits.size() < other.digits.size();
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) 
            return digits[i] < other.digits[i];
    }
    return false;
}