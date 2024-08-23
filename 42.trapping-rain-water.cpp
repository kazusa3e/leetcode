/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        unsigned sum = 0;
        vector<int> lmax(height.size(), -1);
        vector<int> rmax(height.size(), -1);
        for (int ix = 1; ix != height.size(); ++ix) {
            lmax[ix] = max(lmax[ix - 1], height[ix - 1]);
        }
        for (int ix = height.size() - 2; ix >= 0; --ix) {
            rmax[ix] = max(rmax[ix + 1], height[ix + 1]);
        }
        for (auto iter = height.begin(); iter != height.end(); ++iter) {
            if (iter == height.begin()) continue;
            if (iter == height.end() - 1) continue;
            if (lmax[iter - height.begin()] > *iter && rmax[iter - height.begin()] > *iter) {
                auto val = min(lmax[iter - height.begin()], rmax[iter - height.begin()]);
                sum += (val - *iter);
            }
        }
        return sum;
    }
};
// @lc code=end
