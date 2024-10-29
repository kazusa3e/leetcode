/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> results;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(0, std::move(nums));
        return results;
    }

    void backtracking(unsigned begin, vector<int> &&nums) {
        if (begin == nums.size()) {
            results.push_back(nums); return;
        }
        for (unsigned i = begin; i != nums.size(); ++i) {
            swap(nums[i], nums[begin]);
            backtracking(begin + 1, std::move(nums));
            swap(nums[i], nums[begin]);
        }
    }
};
// @lc code=end
