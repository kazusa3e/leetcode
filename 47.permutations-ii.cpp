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
    vector<vector<int>> results_;

    void backtracking(vector<int> bag, vector<int> collections) {
        if (collections.empty()) {
            results_.push_back(bag);
        }
        unordered_set<int> seen;
        for (auto iter = collections.begin(); iter != collections.end(); ++iter) {
            if (auto pos = seen.find(*iter); pos != seen.end()) continue;
            seen.insert(*iter);
            vector<int> b {bag}, c {collections};
            b.push_back(*iter);
            c.erase(c.begin() + (iter - collections.begin()));
            backtracking(b, c);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking({}, nums);
        return results_;
    }
};
// @lc code=end
