/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> results_;
    vector<int> bag_;
    vector<int> candidates_;

    void backtracking(const vector<int>::iterator &pos) {
        results_.push_back(bag_);
        if (pos == candidates_.end()) {
            return;
        }
        for (auto iter = pos; iter != candidates_.end(); ++iter) {
            bag_.push_back(*iter);
            backtracking(iter + 1);
            bag_.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        candidates_ = nums;
        backtracking(candidates_.begin());
        return results_;
    }
};
// @lc code=end
