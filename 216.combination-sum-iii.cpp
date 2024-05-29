/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    vector<vector<int>> results;
    vector<int> path;
    int sum {};

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return results;
    }

    void backtracking(int k, int n, int startIndex) {
        if (k > n) return;
        if (sum > n) return;
        if (path.size() == k) {
            if (sum == n) {
                results.push_back(path);
            }
            return;
        }
        for (int ix = startIndex; ix != 10; ++ix) {
            path.push_back(ix);
            sum += ix;
            backtracking(k, n, ix + 1);
            sum -= ix;
            path.pop_back();
        }
    }
};
// @lc code=end
