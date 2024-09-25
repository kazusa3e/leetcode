/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int left_pos = -1, right_pos = -1;
        for (int ix = 1; ix != nums.size(); ++ix) {
            if (nums[ix - 1] > nums[ix]) {
                left_pos = ix - 1; break;
            }
        }
        for (int ix = nums.size() - 2; ix >= 0; --ix) {
            if (nums[ix] > nums[ix + 1]) {
                right_pos = ix + 1; break;
            }
        }
        if (left_pos == -1 || right_pos == -1) return 0;

        auto min_el = min_element(nums.begin() + left_pos, nums.begin() + right_pos + 1),
            max_el = max_element(nums.begin() + left_pos, nums.begin() + right_pos + 1);

        for (int ix = right_pos + 1; ix != nums.size() && nums[ix] < *max_el; ++ix) {
            right_pos = ix;
        }
        for (int ix = left_pos - 1; ix >= 0 && nums[ix] > *min_el; --ix) {
            left_pos = ix;
        }

        return right_pos - left_pos + 1;
    }
};
// @lc code=end
