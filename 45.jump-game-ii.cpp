/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cover = 0;
        int cnt = 0;
        if (nums.size() == 1) return 0;
        for (int ix = 0; ix <= cover; ) {
            cover = max(cover, ix + nums[ix]);
            if (cover >= nums.size() - 1) {
                cnt += 1; break;
            }
            int m_cover = 0, m_idx = 0;
            for (int i = ix + 1; i != min(ix + 1 + nums[ix], (int) nums.size()); ++i) {
                if (nums[i] + i > m_cover) {
                    m_cover = nums[i] + i;
                    m_idx = i;
                }
            }
            ix = m_idx; cnt += 1;
        }
        return cnt;
    }
};
// @lc code=end
