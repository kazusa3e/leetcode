/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        }
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1, right = 46341;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (x < mid * mid) {
                right = mid;
            } else if (x > mid * mid) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left - 1;
    }
};
// @lc code=end
