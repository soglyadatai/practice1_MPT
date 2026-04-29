#include "long_number.hpp"
#include <iostream>
#include <stdexcept>

using ssY::LongNumber;

LongNumber::LongNumber() {
    length = 1;
    sign = 1;
    numbers = new int[1];
    numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) {
    this->length = length;
    this->sign = sign;
    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = 0;
    }
}

LongNumber::LongNumber(const char* const str) {
    int str_len = get_length(str);

    if (str_len == 0) {
        length = 1;
        sign = 1;
        numbers = new int[1];
        numbers[0] = 0;
        return;
    }

    int start = 0;
    sign = 1;

    if (str[0] == '-') {
        sign = -1;
        start = 1;
    }

    length = str_len - start;

    if (length <= 0) {
        length = 1;
        sign = 1;
        numbers = new int[1];
        numbers[0] = 0;
        return;
    }

    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = str[str_len - 1 - i] - '0';
    }

    while (length > 1 && numbers[length - 1] == 0) {
        length--;
    }

    if (length == 1 && numbers[0] == 0) {
        sign = 1;
    }
}

LongNumber::LongNumber(const LongNumber& x) {
    length = x.length;
    sign = x.sign;

    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }
}

LongNumber::LongNumber(LongNumber&& x) {
    length = x.length;
    sign = x.sign;
    numbers = x.numbers;

    x.length = 0;
    x.sign = 1;
    x.numbers = nullptr;
}

LongNumber::~LongNumber() {
    delete[] numbers;
    numbers = nullptr;
    length = 0;
}

LongNumber& LongNumber::operator=(const char* const str) {
    delete[] numbers;

    int str_len = get_length(str);

    if (str_len == 0) {
        length = 1;
        sign = 1;
        numbers = new int[1];
        numbers[0] = 0;
        return *this;
    }

    int start = 0;
    sign = 1;

    if (str[0] == '-') {
        sign = -1;
        start = 1;
    }

    length = str_len - start;

    if (length <= 0) {
        length = 1;
        sign = 1;
        numbers = new int[1];
        numbers[0] = 0;
        return *this;
    }

    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = str[str_len - 1 - i] - '0';
    }

    while (length > 1 && numbers[length - 1] == 0) {
        length--;
    }

    if (length == 1 && numbers[0] == 0) {
        sign = 1;
    }

    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this == &x) {
        return *this;
    }

    delete[] numbers;

    length = x.length;
    sign = x.sign;
    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }

    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) {
    if (this == &x) {
        return *this;
    }

    delete[] numbers;

    length = x.length;
    sign = x.sign;
    numbers = x.numbers;

    x.length = 0;
    x.sign = 1;
    x.numbers = nullptr;

    return *this;
}

bool LongNumber::operator==(const LongNumber& x) const {
    if (sign != x.sign) {
        return false;
    }

    if (length != x.length) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator>(const LongNumber& x) const {
    if (sign != x.sign) {
        return sign > x.sign;
    }

    if (length != x.length) {
        if (sign == 1) {
            return length > x.length;
        } else {
            return length < x.length;
        }
    }

    for (int i = length - 1; i >= 0; i--) {
        if (numbers[i] != x.numbers[i]) {
            if (sign == 1) {
                return numbers[i] > x.numbers[i];
            } else {
                return numbers[i] < x.numbers[i];
            }
        }
    }

    return false;
}

bool LongNumber::operator<(const LongNumber& x) const {
    if (*this == x) {
        return false;
    }

    return x > *this;
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    LongNumber res;

    if (sign != x.sign) {
        LongNumber tmp = x;
        tmp.sign = -tmp.sign;
        return *this - tmp;
    }

    int max_len = length;

    if (x.length > max_len) {
        max_len = x.length;
    }

    res = LongNumber(max_len + 1, sign);

    int carry = 0;

    for (int i = 0; i < res.length; i++) {
        int a = 0;
        int b = 0;

        if (i < length) {
            a = numbers[i];
        }

        if (i < x.length) {
            b = x.numbers[i];
        }

        int s = a + b + carry;

        res.numbers[i] = s % 10;
        carry = s / 10;
    }

    while (res.length > 1 && res.numbers[res.length - 1] == 0) {
        res.length--;
    }

    if (res.length == 1 && res.numbers[0] == 0) {
        res.sign = 1;
    }

    return res;
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    LongNumber res;

    // a - (-b) = a + b
    if (x.sign == -1) {
        LongNumber tmp = x;
        tmp.sign = 1;
        return *this + tmp;
    }

    if (sign == -1 && x.sign == 1) {
        LongNumber a = *this;
        LongNumber b = x;

        a.sign = 1;
        b.sign = 1;

        res = a + b;
        res.sign = -1;

        if (res.length == 1 && res.numbers[0] == 0) {
            res.sign = 1;
        }

        return res;
    }

    LongNumber left = *this;
    LongNumber right = x;

    left.sign = 1;
    right.sign = 1;

    bool answer_negative = false;

    if (left < right) {
        LongNumber tmp = left;
        left = right;
        right = tmp;
        answer_negative = true;
    }

    res = LongNumber(left.length, 1);

    int borrow = 0;

    for (int i = 0; i < left.length; i++) {
        int a = left.numbers[i];
        int b = 0;

        if (i < right.length) {
            b = right.numbers[i];
        }

        int cur = a - b - borrow;

        if (cur < 0) {
            cur = cur + 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.numbers[i] = cur;
    }

    while (res.length > 1 && res.numbers[res.length - 1] == 0) {
        res.length--;
    }

    if (answer_negative) {
        res.sign = -1;
    }

    if (res.length == 1 && res.numbers[0] == 0) {
        res.sign = 1;
    }

    return res;
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    LongNumber res(length + x.length, sign * x.sign);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < x.length; j++) {
            res.numbers[i + j] = res.numbers[i + j] + numbers[i] * x.numbers[j];
        }
    }

    for (int i = 0; i < res.length - 1; i++) {
        if (res.numbers[i] >= 10) {
            res.numbers[i + 1] = res.numbers[i + 1] + res.numbers[i] / 10;
            res.numbers[i] = res.numbers[i] % 10;
        }
    }

    while (res.length > 1 && res.numbers[res.length - 1] == 0) {
        res.length--;
    }

    if (res.length == 1 && res.numbers[0] == 0) {
        res.sign = 1;
    }

    return res;
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    LongNumber zero("0");
    LongNumber one("1");

    if (x == zero) {
        throw std::runtime_error("division by zero");
    }

    LongNumber a = *this;
    LongNumber b = x;

    a.sign = 1;
    b.sign = 1;

    LongNumber ans("0");

    while (a > b || a == b) {
        a = a - b;
        ans = ans + one;
    }

    ans.sign = sign * x.sign;

    if (ans.length == 1 && ans.numbers[0] == 0) {
        ans.sign = 1;
    }

    return ans;
}

LongNumber LongNumber::operator%(const LongNumber& x) const {
    LongNumber zero("0");

    if (x == zero) {
        throw std::runtime_error("division by zero");
    }

    LongNumber q = *this / x;
    LongNumber res = *this - q * x;

    return res;
}

bool LongNumber::is_negative() const noexcept {
    return sign == -1;
}

int LongNumber::get_length(const char* const str) const noexcept {
    if (str == nullptr) {
        return 0;
    }

    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

namespace ssY {
    std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
        if (x.sign == -1) {
            os << '-';
        }

        for (int i = x.length - 1; i >= 0; i--) {
            os << x.numbers[i];
        }

        return os;
    }
}