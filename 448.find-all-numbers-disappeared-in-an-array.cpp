/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (auto ix = 0ull; ix != nums.size(); ++ix) {
            auto key = abs(nums[ix]) - 1;
            if (nums[key] > 0) nums[key] = -nums[key];
        }
        for (auto ix = 0ull; ix != nums.size(); ++ix) {
            if (nums[ix] > 0) ret.push_back(ix + 1);
        }
        return ret;
    }
};
// @lc code=end
