/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<unsigned long long> memo(max(n + 1, 3), 0);
        memo[0] = 0; memo[1] = 1; memo[2] = 1;
        if (n <= 2) return memo[n];
        for (auto i = 3ull; i != n + 1; ++i) {
            memo[i] = accumulate(memo.begin() + i - 3, memo.begin() + i, 0);
        }
        return memo.back();
    }
};
// @lc code=end
