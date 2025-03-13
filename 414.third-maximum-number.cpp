/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        auto m1 = numeric_limits<long>::min(),
            m2 = numeric_limits<long>::min(),
            m3 = numeric_limits<long>::min();
        for (const auto &el : nums) {
            if (el == m1 || el == m2 || el == m3) continue;
            if (el > m1) {
                m3 = m2; m2 = m1; m1 = el;
            } else if (el > m2) {
                m3 = m2; m2 = el;
            } else if (el > m3) {
                m3 = el;
            }
        }
        return (m3 == numeric_limits<long>::min()) ? m1 : m3;
    }
};
// @lc code=end
