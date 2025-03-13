/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return {};
        sort(nums.begin(), nums.end());
        vector<int> ret;
        for (auto ix = 1ull; ix != nums.size(); ++ix) {
            if (nums[ix] == nums[ix - 1]) {
                if (ret.empty()) ret.push_back(nums[ix]);
                else if (nums[ix] != ret.back()) ret.push_back(nums[ix]);
            }
        }
        return ret;
    }
};
// @lc code=end
