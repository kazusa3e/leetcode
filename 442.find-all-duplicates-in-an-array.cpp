/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return {};
        vector<int> ret;
        for (auto ix = 0ull; ix != nums.size(); ++ix) {
            auto key = abs(nums[ix]) - 1;
            if (nums[key] < 0) {
                ret.push_back(abs(nums[ix]));
            } else {
                nums[key] = -nums[key];
            }
        }
        return ret;
    }
};
// @lc code=end
