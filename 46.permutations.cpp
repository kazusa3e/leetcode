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
    vector<int> nums_;
    vector<int> bag_;
    vector<vector<int>> results_;
    void backtracking(vector<int> candidates) {
        if (candidates.empty()) {
            results_.push_back(bag_);
            return;
        }
        for (auto iter = candidates.begin(); iter != candidates.end(); ++iter) {
            bag_.push_back(*iter);
            vector<int> c {candidates};
            c.erase(c.begin() + distance(candidates.begin(), iter));
            backtracking(c);
            bag_.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        nums_ = nums;
        backtracking(nums_);
        return results_;
    }
};
// @lc code=end
