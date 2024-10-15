/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if (k == 0) {
            unsigned cnt = 0, m_max = 0;
            for (auto el : nums) {
                if (el == 1) cnt += 1;
                else cnt = 0;
                m_max = max(m_max, cnt);
            }
            return m_max;
        }
        auto l = nums.begin(), r = nums.begin() + 1;
        unsigned win = 1;
        deque<int> gaps;
        if (*l == 0) gaps.push_back(0);
        while (r != nums.end()) {
            if (*r == 1) {
                ++r;
                win = max(win, (unsigned) distance(l, r));
            } else {
                if (gaps.size() != k) {
                    gaps.push_back(distance(nums.begin(), r)); ++r;
                    win = max(win, (unsigned) distance(l, r));
                } else {
                    l = nums.begin() + gaps.front() + 1; gaps.pop_front();
                    gaps.push_back(distance(nums.begin(), r)); ++r;
                    win = max(win, (unsigned) distance(l, r));
                }
            }
        }
        return win;
    }
};
// @lc code=end
