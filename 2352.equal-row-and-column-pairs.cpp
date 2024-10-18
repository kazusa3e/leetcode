/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unsigned ans = 0;
        map<vector<int>, unsigned> m;
        for (const auto &row : grid) m[row] += 1;
        for (unsigned j = 0; j != grid.size(); ++j) {
            vector<int> col;
            transform(grid.begin(), grid.end(), back_inserter(col), [&j](const vector<int> &row) {
                return row[j];
            });
            ans += m[col];
        }
        return ans;
    }

};
// @lc code=end
