/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        if (target < nums.front() || target > nums.back()) {
            return {-1, -1};
        }
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target) - 1;
        if (*left == target) {
            return {static_cast<int>(distance(nums.begin(), left)), static_cast<int>(distance(nums.begin(), right)) };
        } else {
            return {-1, -1};
        }

    }
};
// @lc code=end
