/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
        for (const auto el : nums) {
            x1 ^= (x2 & el);
            x2 ^= el;
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }
        return x2;
    }
};
// @lc code=end
