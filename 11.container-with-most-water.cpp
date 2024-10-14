/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int m_max = numeric_limits<int>::min();
        auto l = height.begin(), r = height.end() - 1;
        while (l < r) {
            m_max = max(m_max, (int) distance(l, r) * min(*l, *r));
            (*l < *r) ? ++l : --r;
        }
        return m_max;
    }
};
// @lc code=end
