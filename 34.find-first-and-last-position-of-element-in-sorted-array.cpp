/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

#include <vector>
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
        using size_type = decltype(nums.size());
        size_type idx = 0;
        bool found = false;
        size_type left = 0, right = nums.size();
        while (left < right) {
            size_type mid = left + ((right - left) >> 1);
            if (target < nums.at(mid)) {
                right = mid;
            } else if (target > nums.at(mid)) {
                left = mid + 1;
            } else {
                found = true;
                idx = mid;
                break;
            }
        }
        if (!found) {
            return {-1, -1};
        }
        left = right = idx;
        while (left > 0 && nums.at(left - 1) == target) {
            left -= 1;
        }
        while (right < nums.size() - 1 && nums.at(right + 1) == target) {
            right += 1;
        }
        return {static_cast<int>(left), static_cast<int>(right)};
    }
};
// @lc code=end
