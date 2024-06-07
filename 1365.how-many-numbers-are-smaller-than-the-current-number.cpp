/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> t(101, 0);
        for (auto el : nums) t[el] += 1;
        int acc = 0;
        for (int ix = 0; ix != 101; ++ix) {
            int tmp = t[ix];
            t[ix] = acc;
            acc += tmp;
        }
        vector<int> ret(nums.size(), 0);
        for (int ix = 0; ix != ret.size(); ++ix) {
            ret[ix] = t[nums[ix]];
        }
        return ret;
    }
};
// @lc code=end
