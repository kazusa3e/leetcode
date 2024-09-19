/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int diff = 0;
        int cnt = 1;
        for (int ix = 0; ix != nums.size() - 1; ++ix) {
            if (nums[ix] < nums[ix + 1]) {
                if (diff == 0 || diff == 1) {
                    diff = -1; cnt += 1;
                }
            } else if (nums[ix] > nums[ix + 1]) {
                if (diff == 0 || diff == -1) {
                    diff = 1; cnt += 1;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
