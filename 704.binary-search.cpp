/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        long left = 0, right = nums.size() - 1;
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
