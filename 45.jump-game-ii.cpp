/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), numeric_limits<int>::max()); dp[dp.size() - 1] = 0;
        for (int ix = dp.size() - 2; ix >= 0; --ix) {
            dp[ix] = *min_element(
                dp.begin() + ix + 1,
                min(dp.begin() + ix + 1 + nums[ix], dp.end())
            ) + 1;
        }
        return dp[0];
    }
};
// @lc code=end
