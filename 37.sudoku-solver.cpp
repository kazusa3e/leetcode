/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>> &board) {
        for (unsigned i = 0; i != 9; ++i) {
            for (unsigned j = 0; j != 9; ++j) {
                if (board[i][j] != '.') continue;
                for (unsigned el = 1; el != 10; ++el) {
                    if (is_valid(board, i, j, el)) {
                        board[i][j] = '0' + el;
                        if (backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool is_valid(const vector<vector<char>> &board, unsigned row, unsigned col, unsigned val) {
        for (unsigned i = 0; i != 9; ++i) {
            if (board[i][col] - '0' == val) return false;
        }
        for (unsigned j = 0; j != 9; ++j) {
            if (board[row][j] - '0' == val) return false;
        }
        unsigned block_row = row / 3, block_col = col / 3;
        for (unsigned i = block_row * 3; i != (block_row + 1) * 3; ++i) {
            for (unsigned j = block_col * 3; j != (block_col + 1) * 3; ++j) {
                if (board[i][j] - '0' == val) return false;
            }
        }

        return true;
    }


};
// @lc code=end
