/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.cbegin(), nums.cend(), nums.begin());
        return nums;
    }
};
// @lc code=end
