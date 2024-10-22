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
        constexpr unsigned num_bits = 32;
        // return ((a | b) ^ c) + (a & b & ((a | b) ^ c));
        return bitset<num_bits> ((a | b) ^ c).count()
            + bitset<num_bits> (a & b & (~c)).count();
    }
};
// @lc code=end
