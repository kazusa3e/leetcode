/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:

    long long combine(long long t, long long s) const {
        if (s > t - s) s = t - s;
        long long ret = 1;
        for (long long i = 1; i <= s; ++i) {
            ret *= t - s + i; ret /= i;
        }
        return ret;
    }

    int uniquePaths(int m, int n) {
        return combine(m + n - 2, n - 1);
    }
};
// @lc code=end
