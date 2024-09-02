/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

#include <vector>
#include <limits>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int m = numeric_limits<int>::min();
        int acc = 0;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            acc += *iter;
            m = max(m, acc);
            if (acc < 0) acc = 0;
        }
        return m;
    }
};
// @lc code=end
