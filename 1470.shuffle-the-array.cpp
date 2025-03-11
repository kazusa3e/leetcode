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
        auto iter = nums.begin();
        for (auto i = nums.begin(), j = nums.begin() + n; i != nums.begin() + n; ++i, ++j) {
            *(iter++) |= (*i << 16); *(iter++) |= (*j << 16);
        }
        for (auto &el : nums) {
            el = (el >> 16) & 0x0000ffff;
        }
        return nums;
    }
};
// @lc code=end
