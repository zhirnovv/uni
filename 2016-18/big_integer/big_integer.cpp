//
// Created by Vasily Zhirnov on 02/05/2018.
//

#include "big_integer.h"

const uint32_t base = std::numeric_limits<uint32_t>::max();

void big_integer::remove_leading_zeros() {
    std::vector<uint32_t>::iterator it;
    for (it = data.end() - 1; it >= data.begin(); it--) {
        if (*it != 0) {
            break;
        }
    }

    data.erase(it + 1, data.end());
}

big_integer::big_integer() = default;

big_integer::big_integer(big_integer const &other)
        : data(other.data), sign(other.sign) {}

big_integer::big_integer(int a) {
    sign = a < 0;
    a = abs(a);

    while (a != 0) {
        data.push_back(a % base);
        a /= base;
    }
}

big_integer::~big_integer() = default;

big_integer& big_integer::operator=(big_integer const& other) = default;

big_integer& big_integer::operator+=(big_integer const& other) {
    if (sign) {
        *this = -*this - other;
        return *this;
    }

    if (other.sign) {
        return *this -= other;
    }

    uint64_t d = 0;
    uint64_t temp;

    while (data.size() < other.data.size()) {
        data.push_back(0);
    }

    while (other.data.size() < data.size()) {
        other.data.push_back(0);
    }

    for (std::size_t i = 0; i < data.size(); i++) {
        temp = data[i] + other.data[i] + d;
        d = temp / base;
        data[i] = static_cast<uint32_t>(temp % base);
    }

    data.push_back(static_cast<uint32_t>(d));
    remove_leading_zeros();

    return *this;
}

big_integer operator+(big_integer a, big_integer const& b) {
    return a += b;
}

big_integer big_integer::operator+() const {
    return *this;
}

big_integer big_integer::operator-() const {
    big_integer result = *this;
    result.sign ^= result.sign;
    return result;
}
