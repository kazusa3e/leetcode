/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        if (num == 0 || num == 1) {
            return true;
        }
        int left = 0, right = 46341;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (num < mid * mid) {
                right = mid;
            } else if (num > mid * mid) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
