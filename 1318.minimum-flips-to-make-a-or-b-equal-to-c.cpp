/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start

#include <bitset>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __popcount(a | b ^ c) + __popcount(a & b & (~c));
    }
};
// @lc code=end
