/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> candidates_;
    int target_;
    vector<vector<int>> results_;
    vector<int> bag_;
    int sum_ {};
    void backtracking(vector<int>::iterator begin) {
        if (sum_ == target_) {
            results_.push_back(bag_);
            return;
        }
        if (sum_ > target_) return;
        for (auto iter = begin; iter != candidates_.end(); ++iter) {
            bag_.push_back(*iter);
            sum_ += *iter;
            backtracking(iter);
            bag_.pop_back();
            sum_ -= *iter;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidates_ = candidates;
        target_ = target;
        backtracking(candidates_.begin());
        return results_;
    }

};
// @lc code=end
