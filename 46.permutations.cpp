/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> results_;
    void backtracking(vector<int> bag, vector<int> collections) {
        if (collections.empty()) {
            results_.push_back(bag);
        }
        for (auto iter = collections.begin(); iter != collections.end(); ++iter) {
            vector<int> b {bag}, c {collections};
            b.push_back(*iter);
            c.erase(c.begin() + (iter - collections.begin()));
            backtracking(b, c);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking({}, nums);
        return results_;
    }
};
// @lc code=end
