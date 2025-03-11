/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        array<unsigned, 100> umap {};
        for (const auto &el : nums) ++umap[el - 1];
        unsigned cnt = 0;
        for (const auto &el : umap) {
            if (el > 1) cnt += el * (el - 1) / 2;
        }
        return cnt;
    }
};
// @lc code=end
