/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        auto non_divisible_sum = 0ull, divisible_sum = 0ull;
        for (auto ix = 1; ix <= n; ++ix) {
            (ix % m == 0) ? divisible_sum += ix : non_divisible_sum += ix;
        }
        return non_divisible_sum - divisible_sum;
    }
};
// @lc code=end
