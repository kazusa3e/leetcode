/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int ix = 0; ix <= cover; ++ix) {
            cover = max(nums[ix] + ix, cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
// @lc code=end
