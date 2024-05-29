/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> candidates_;
    vector<vector<int>> results_;
    vector<int> bag_;

    void backtracking(vector<int>::iterator pos) {
        results_.push_back(bag_);
        if (pos == candidates_.end()) {
            return;
        }
        unordered_set<int> seen;
        for (auto iter = pos; iter != candidates_.end(); ++iter) {
            if (auto pos = seen.find(*iter); pos != seen.end()) {
                continue;
            }
            seen.insert(*iter);
            bag_.push_back(*iter);
            backtracking(iter + 1);
            bag_.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        candidates_ = nums;
        sort(candidates_.begin(), candidates_.end());
        backtracking(candidates_.begin());
        return results_;
    }
};
// @lc code=end
