/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> digits;
        while (k != 0) {
            digits.push_back(k % 10); k /= 10;
        }
        reverse(digits.begin(), digits.end());

        vector<int> ret;
        unsigned carry = 0;
        auto i1 = num.rbegin(), i2 = digits.rbegin();
        while (i1 != num.rend() && i2 != digits.rend()) {
            unsigned val = *i1 + *i2 + carry;
            carry = (val >= 10) ? 1 : 0;
            ret.push_back(val % 10);
            ++i1; ++i2;
        }
        while (i1 != num.rend()) {
            unsigned val = *i1 + carry;
            carry = (val >= 10) ? 1 : 0;
            ret.push_back(val % 10);
            ++i1;
        }
        while (i2 != digits.rend()) {
            unsigned val = *i2 + carry;
            carry = (val >= 10) ? 1 : 0;
            ret.push_back(val % 10);
            ++i2;
        }
        if (carry) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
