/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto l = nums.begin(), r = nums.begin() + 1;
        unsigned num_zeros = (nums.front() == 0) ? 1 : 0;
        int win = 1;
        while (r != nums.end()) {
            if (*r == 1) {
                ++r; win = max(win, (int) distance(l, r));
            } else {
                if (num_zeros == 0) {
                    ++r; win = max(win, (int) distance(l, r));
                    num_zeros += 1;
                } else {
                    while (*l != 0) ++l; ++l;
                    win = max(win, (int) distance(l, r));
                    num_zeros = 0;
                }
            }
        }
        return win - 1;
    }
};
// @lc code=end
