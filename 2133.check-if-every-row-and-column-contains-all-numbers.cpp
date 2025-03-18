/*
 * @lc app=leetcode id=2133 lang=cpp
 *
 * [2133] Check if Every Row and Column Contains All Numbers
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        auto is_row_valid = [&matrix] (size_t row) -> bool {
            counter c(matrix[row].size());
            for (auto j = 0ull; j != matrix[row].size(); ++j) {
                if (!c.add(matrix[row][j] - 1)) return false;
            }
            return true;
        };
        auto is_column_valid = [&matrix] (size_t col) -> bool {
            counter c(matrix.size());
            for (auto i = 0ull; i != matrix.size(); ++i) {
                if (!c.add(matrix[i][col] - 1)) return false;
            }
            return true;
        };
        for (auto i = 0ull; i != matrix.size(); ++i) {
            if (!is_row_valid(i)) return false;
        }
        for (auto j = 0ull; j != matrix.front().size(); ++j) {
            if (!is_column_valid(j)) return false;
        }
        return true;
    }
private:
    struct counter {
        vector<bool> seen;
        counter(size_t n) { seen.resize(n, false); }
        bool add(size_t n) {
            if (seen[n]) return false;
            seen[n] = true;
            return true;
        };
    };
};
// @lc code=end
