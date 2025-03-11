/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        return __popcount(n);
    }
};
// @lc code=end
