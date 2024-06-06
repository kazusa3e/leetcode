/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> nums_;
    vector<int> bag_;
    vector<vector<int>> results_;
    void backtracking(vector<int>::iterator begin) {
        if (bag_.size() >= 2) {
            results_.push_back(bag_);
        }
        unordered_set<int> seen;
        for (auto iter = begin; iter != nums_.end(); ++iter) {
            if (auto pos = seen.find(*iter); pos != seen.end()) continue;
            seen.insert(*iter);
            if (!bag_.empty() && *iter < bag_.back()) continue;
            bag_.push_back(*iter);
            backtracking(iter + 1);
            bag_.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        nums_ = nums;
        backtracking(nums_.begin());
        return results_;
    }
};
// @lc code=end
