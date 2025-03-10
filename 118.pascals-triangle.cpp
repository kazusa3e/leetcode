/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (auto row = 0ull; row != numRows; ++row) {
            vector<int> curr(row + 1, 1);
            for (auto col = 1ull; col < row; ++col) {
                curr[col] = ret[row - 1][col - 1] + ret[row - 1][col];
            }
            ret.push_back(std::move(curr));
        }
        return ret;
    }
};
// @lc code=end
