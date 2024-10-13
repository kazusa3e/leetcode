/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<unsigned> digits(num1.size() + num2.size(), 0);
        for (auto i1 = num1.rbegin(); i1 != num1.rend(); ++i1) {
            for (auto i2 = num2.rbegin(); i2 != num2.rend(); ++i2) {
                unsigned dif = distance(num1.rbegin(), i1) + distance(num2.rbegin(), i2);
                *(digits.rbegin() + dif) += ((*i1 - '0') * (*i2 - '0'));
            }
        }
        for (auto iter = digits.rbegin(); iter != digits.rend() - 1; ++iter) {
            *(iter + 1) += (*iter / 10);
            *iter = (*iter % 10);
        }
        auto pos = find_if_not(digits.begin(), digits.end(), [](unsigned x) { return x == 0; });
        string ret;
        for_each(pos, digits.end(), [&ret](unsigned x) {
            ret += (x + '0');
        });
        return ret;
    }
};
// @lc code=end