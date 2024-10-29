/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        do {
            results.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return results;
    }
};
// @lc code=end
