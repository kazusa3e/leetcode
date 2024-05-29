/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> results;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return results;
    }

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            results.push_back(path);
        }
        for (int ix = startIndex; ix <= n; ++ix) {
            if (ix + (k - path.size()) - 1 > n) break;
            path.push_back(ix);
            backtracking(n, k, ix + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
