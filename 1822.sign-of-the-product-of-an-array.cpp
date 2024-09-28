/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ret = 1;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == 0) return 0;
            if (*iter < 0) {
                ret *= -1;
            }
        }
        return ret;
    }
};
// @lc code=end
