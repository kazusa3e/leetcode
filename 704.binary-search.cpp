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
            return (nums.at(0) == target) ? 0 : -1;
        }
        using size_type = decltype(nums.size());
        size_type left = 0, right = nums.size();
        while (left < right) {
            size_type mid = ((right - left) >> 1) + left;
            if (target < nums.at(mid)) {
                right = mid;
            } else if (target > nums.at(mid)) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
