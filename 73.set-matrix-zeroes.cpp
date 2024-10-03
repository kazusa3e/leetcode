/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<unsigned> rows, cols;
        for (unsigned i = 0; i != matrix.size(); ++i) {
            for (unsigned j = 0; j != matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i); cols.insert(j);
                }
            }
        }

        for (auto r : rows) {
            fill(matrix[r].begin(), matrix[r].end(), 0);
        }

        for (auto c : cols) {
            for_each(matrix.begin(), matrix.end(), [&c](auto &row) {
                row[c] = 0;
            });
        }
    }
};
// @lc code=end
