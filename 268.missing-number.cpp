/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = accumulate(nums.cbegin(), nums.cend(), 0);
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};
// @lc code=end
