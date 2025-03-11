/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ret(nums.size());
        for (auto ix = 0ull; ix != nums.size(); ++ix) ret[ix] = nums[nums[ix]];
        return ret;
    }
};
// @lc code=end
