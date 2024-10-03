/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start

#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        deque<unsigned> digits;
        unsigned carry = 0;
        auto i1 = num1.rbegin(), i2 = num2.rbegin();
        while (i1 != num1.rend() && i2 != num2.rend()) {
            unsigned val = (*i1 - '0') + (*i2 - '0') + carry;
            carry = 0;
            digits.push_front(val % 10);
            carry = val / 10;
            ++i1; ++i2;
        }
        while (i1 != num1.rend()) {
            unsigned val = (*i1 - '0') + carry;
            carry = 0;
            digits.push_front(val % 10);
            carry = val / 10;
            ++i1;
        }
        while (i2 != num2.rend()) {
            unsigned val = (*i2 - '0') + carry;
            carry = 0;
            digits.push_front(val % 10);
            carry = val / 10;
            ++i2;
        }
        string ret;
        if (carry) digits.push_front(1);
        transform(digits.begin(), digits.end(), back_inserter(ret), [](int v) {
            return v + '0';
        });
        return ret;
    }
};
// @lc code=end
