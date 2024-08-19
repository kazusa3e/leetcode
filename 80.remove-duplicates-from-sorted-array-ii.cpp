/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        auto i = nums.begin(), j = nums.begin();
        for (; j != nums.end(); ++j) {
            if (distance(nums.begin(), i) < 2 || *j != *(i - 2)) {
                *i = *j; i += 1;
            }
        }
        return i - nums.begin();
    }
};
// @lc code=end
