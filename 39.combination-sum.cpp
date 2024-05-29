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
public:

    vector<vector<int>> results;
    vector<int> bag;

    vector<int> candicates_;
    int target_;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candicates_ = candidates;
        sort(candicates_.begin(), candicates_.end());
        target_ = target;

        backtracking(candicates_.begin());

        return results;
    }

    void backtracking(const vector<int>::iterator &begin) {
        auto sum = accumulate(bag.begin(), bag.end(), 0);
        if (sum == target_) {
            results.push_back(bag);
            return;
        }
        if (sum > target_) {
            return;
        }
        for (auto iter = begin; iter != candicates_.end(); ++iter) {
            bag.push_back(*iter);
            backtracking(iter);
            bag.pop_back();
        }
    }
};
// @lc code=end
