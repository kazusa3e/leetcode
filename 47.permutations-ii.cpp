/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> bag_;
    vector<vector<int>> results_;
    void backtracking(vector<int> candidates) {
        if (candidates.empty()) {
            results_.push_back(bag_);
            return;
        }
        unordered_set<int> seen;
        for (auto iter = candidates.begin(); iter != candidates.end(); ++iter) {
            if (auto pos = seen.find(*iter); pos != seen.end()) continue;
            seen.insert(*iter);
            bag_.push_back(*iter);
            vector<int> c {candidates};
            c.erase(c.begin() + distance(candidates.begin(), iter));
            backtracking(c);
            bag_.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking(nums);
        return results_;
    }
};
// @lc code=end
