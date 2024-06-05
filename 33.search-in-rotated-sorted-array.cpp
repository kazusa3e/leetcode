/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 2) {
            if (auto pos = find(nums.begin(), nums.end(), target); pos != nums.end()) {
                return pos - nums.begin();
            } else {
                return -1;
            }
        }
        long left = 0L, right = nums.size() - 1;
        while (left < right) {
            long mid = left + ((right - left) >> 1);
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (target < nums.back()) {
            left = left; right = nums.size() - 1;
        } else if (target > nums.back()) {
            right = left - 1; left = 0;
        } else {
            return nums.size() - 1;
        }
        while (left <= right) {
            long mid = left + ((right - left) >> 1);
            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
