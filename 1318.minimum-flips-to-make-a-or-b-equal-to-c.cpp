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
        constexpr unsigned bits = 32;
        bitset<bits> bsa (a), bsb (b), bsc (c);
        unsigned cnt = 0;
        for (unsigned ix = 0; ix != bits; ++ix) {
            if (bsc[ix] == 0) {
                if (bsa[ix] == 1) cnt += 1;
                if (bsb[ix] == 1) cnt += 1;
            }
            if (bsc[ix] == 1) {
                if (bsa[ix] == 0 && bsb[ix] == 0) cnt += 1;
            }
        }
        return cnt;
    }
};
// @lc code=end
