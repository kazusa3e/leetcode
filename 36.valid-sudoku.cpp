/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

using namespace std;

class counter {
public:
    vector<bool> seen = vector<bool>(9, false);
    bool add(char el) {
        if (el == '.') return true;
        if (seen[el - '1']) return false;
        seen[el - '1'] = true;
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto is_row_valid = [&board](size_t row) -> bool {
            counter c;
            for (auto j = 0ull; j != 9; ++j) {
                if (!c.add(board[row][j])) return false;
            }
            return true;
        };
        auto is_col_valid = [&board](size_t col) -> bool {
            counter c;
            for (auto i = 0ull; i != 9; ++i) {
                if (!c.add(board[i][col])) return false;
            }
            return true;
        };
        auto is_area_valid = [&board](size_t row, size_t col) -> bool {
            counter c;
            for (auto i = row; i != row + 3; ++i) {
                for (auto j = col; j != col + 3; ++j) {
                    if (!c.add(board[i][j])) return false;
                }
            }
            return true;
        };

        for (auto i = 0ull; i != 9; ++i) if (!is_row_valid(i)) return false;
        for (auto j = 0ull; j != 9; ++j) if (!is_col_valid(j)) return false;
        for (auto i = 0ull; i != 9; i += 3) {
            for (auto j = 0ull; j != 9; j += 3) {
                if (!is_area_valid(i, j)) return false;
            }
        }
        return true;
    }
};
// @lc code=end
