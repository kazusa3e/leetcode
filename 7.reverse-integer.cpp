/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool sign = (x >= 0);
        vector<unsigned> digits;
        while (x != 0) {
            digits.push_back(abs(x % 10));
            x /= 10;
        }
        int ret = 0;
        for (auto el : digits) {
            if (ret > 214748364) {
                ret = 0; break;
            }
            ret *= 10; ret += el;
        }
        return (sign) ? ret : -ret;
    }
};
// @lc code=end
