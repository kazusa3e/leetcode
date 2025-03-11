/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(n * 2); auto iter = ret.begin();
        for (auto i = nums.begin(), j = nums.begin() + n; i != nums.begin() + n; ++i, ++j) {
            *(iter++) = *i; *(iter++) = *j;
        }
        return ret;
    }
};
// @lc code=end
