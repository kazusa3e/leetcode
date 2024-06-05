/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            return (nums[1] > nums[0]) ? 1 : 0;
        }
        auto at = [&nums](int ix) {
            if (ix < 0 || ix >= nums.size()) return 0;
            return nums[ix];
        };
        long left = 0, right = nums.size() - 1;
        while (left <= right) {
            long mid = left + ((right - left) >> 1);
            if (nums[mid] > at(mid - 1) && nums[mid] > at(mid + 1)) return mid;
            if (nums[mid] < at(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
