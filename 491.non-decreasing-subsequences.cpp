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
    vector<vector<int>> results_;
    vector<int> bag_;

    void backtracking(vector<int>::iterator pos) {
        if (bag_.size() >= 2) {
            results_.push_back(bag_);
        }
        unordered_set<int> seen;
        for (auto iter = pos; iter != nums_.end(); ++iter) {
            if (auto f = seen.find(*iter); f != seen.end()) continue;
            seen.insert(*iter);
            if (bag_.empty() || *iter >= bag_.back()) {
                bag_.push_back(*iter);
                backtracking(iter + 1);
                bag_.pop_back();
            }
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
