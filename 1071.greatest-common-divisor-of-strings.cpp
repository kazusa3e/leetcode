/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start

#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        auto sz = gcd(str1.size(), str2.size());
        return string {str1.begin(), str1.begin() + sz};
    }

};
// @lc code=end
