/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    int n_;
    vector<vector<string>> results;
    vector<vector<bool>> board;

    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        board = vector<vector<bool>>(n_ + 1, vector<bool>(n_, false));
        backtracking(1);
        return results;
    }

    void backtracking(unsigned level) {
        if (level == n_ + 1) {
            collect_result(); return;
        }
        auto &curr = board[level];
        for (unsigned ix = 0; ix != n_; ++ix) {
            if (is_valid(level, ix)) {
                curr[ix] = true;
                backtracking(level + 1);
                curr[ix] = false;
            }
        }
    }

    bool is_valid(unsigned level, unsigned ix) {
        for (unsigned row = 1; row != level; ++row) {
            if (board[row][ix]) return false;
        }

        for (unsigned i = level - 1, j = ix + 1; i != 0 && j != n_; --i, ++j) {
            if (board[i][j]) return false;
        }

        for (int i = level - 1, j = ix - 1; i != 0 && j >= 0; --i, --j) {
            if (board[i][j]) return false;
        }
        return true;
    }

    void collect_result() {
        vector<string> ans;
        for (auto row = board.begin() + 1; row != board.end(); ++row) {
            string s;
            for (auto el : *row) { s += (el) ? "Q" : "."; }
            ans.push_back(s);
        }
        results.push_back(ans);
    }
};
// @lc code=end
