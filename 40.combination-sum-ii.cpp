/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

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
        if (begin == candidates_.end()) return;
        unordered_set<int> seen;
        for (auto iter = begin; iter != candidates_.end(); ++iter) {
            if (auto pos = seen.find(*iter); pos != seen.end()) {
                continue;
            }
            seen.insert(*iter);
            bag_.push_back(*iter);
            sum_ += *iter;
            backtracking(iter + 1);
            bag_.pop_back();
            sum_ -= *iter;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidates_ = candidates;
        target_ = target;
        sort(candidates_.begin(), candidates_.end());
        backtracking(candidates_.begin());
        return results_;
    }
};
// @lc code=end
