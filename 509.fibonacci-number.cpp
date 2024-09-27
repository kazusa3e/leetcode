/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start

#include <vector>

using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int> fibs(max(n + 1, 2), 0);
        fibs[0] = 0; fibs[1] = 1;
        for (int ix = 2; ix <= n; ++ix) {
            fibs[ix] = fibs[ix - 1] + fibs[ix - 2];
        }
        return fibs[n];
    }
};
// @lc code=end
