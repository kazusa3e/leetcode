/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        int diff = 2;
        for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
            int delta = *iter - *(iter - 1);
            if (diff == 2) {
                if (delta == 0) continue;
                diff = (delta > 0) ? 1 : -1;
            } else {
                if (diff * delta < 0) return false;
            }
        }
        return true;
    }
};
// @lc code=end
