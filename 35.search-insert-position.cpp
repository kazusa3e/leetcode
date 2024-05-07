/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return (target <= nums.at(0)) ? 0 : 1;
        }
        if (target > nums.back()) {
            return nums.size();
        }
        using size_type = decltype(nums.size());
        size_type left = 0, right = nums.size();
        while (left < right) {
            size_type mid = left + ((right - left) >> 1);
            if (target < nums.at(mid)) {
                right = mid;
            } else if (target > nums.at(mid)) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
// @lc code=end
