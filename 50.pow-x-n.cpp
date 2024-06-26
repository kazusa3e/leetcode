/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double val = myPow(x, n / 2);
        if (n > 0) {
            return (n % 2 == 0) ? val * val : val * val * x;
        } else {
            return (n % 2 == 0) ? val * val : val * val / x;
        }
    }
};
// @lc code=end
