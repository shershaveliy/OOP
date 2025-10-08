#ifndef SIX_H
#define SIX_H

#include <vector>
#include <string>
#include <initializer_list>

class Six {
private:
    std::vector<unsigned char> digits;

public:
    Six();
    Six(const size_t &n, unsigned char t = 0);
    Six(const std::initializer_list<unsigned char> &t);
    Six(const std::string &t);
    Six(const Six &other);
    Six(Six&& other) noexcept;
    virtual ~Six() noexcept;

    Six add(const Six& other) const;
    Six subtract(const Six& other) const;
    Six copy() const;
    
    Six addAssign(const Six& other) const;
    Six subtractAssign(const Six& other) const;
    
    bool equals(const Six& other) const;
    bool greaterThan(const Six& other) const;
    bool lessThan(const Six& other) const;

    void print() const;
};

#endif