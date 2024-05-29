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
    vector<vector<int>> results_;
    vector<int> bag_;
    vector<int> candidates_;
    int target_;

public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidates_ = candidates;
        sort(candidates_.begin(), candidates_.end());
        target_ = target;

        backtracking(candidates_.begin());
        return results_;
    }

    void backtracking(vector<int>::iterator begin) {
        auto sum = accumulate(bag_.begin(), bag_.end(), 0);
        if (sum > target_) return;
        if (sum == target_) {
            results_.push_back(bag_);
            return;
        }
        unordered_set<int> used;
        for (auto iter = begin; iter != candidates_.end(); ++iter) {
            if (auto pos = used.find(*iter); pos != used.end()) continue;
            used.insert(*iter);
            bag_.push_back(*iter);
            backtracking(iter + 1);
            bag_.pop_back();
        }
    }
};
// @lc code=end
