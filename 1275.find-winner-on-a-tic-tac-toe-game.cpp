/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    using grid = vector<vector<char>>;

    string tictactoe(vector<vector<int>>& moves) {
        grid board = {
            { ' ', ' ', ' ' },
            { ' ', ' ', ' ' },
            { ' ', ' ', ' ' },
        };
        bool turn = false;  // false for A
        for_each(moves.begin(), moves.end(), [&](const vector<int> &m) {
            if (turn) {
                board[m[0]][m[1]] = 'o';
            } else {
                board[m[0]][m[1]] = 'x';
            }
            turn = !turn;
        });
        auto as = check(board, 'x'), bs = check(board, 'o');
        if (as) return "A";
        if (bs) return "B";
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }

    bool check(const grid &board, char who) {
        for (auto i = 0; i != 3; ++i) {
            vector<int> row { board[i][0], board[i][1], board[i][2] };
            if (all_of(row.begin(), row.end(), [&](int el) { return el == who; })) {
                return true;
            }
        }
        for (auto j = 0; j != 3; ++j) {
            vector<int> col { board[0][j], board[1][j], board[2][j] };
            if (all_of(col.begin(), col.end(), [&](int el) { return el == who; })) {
                return true;
            }
        }

        vector<int> diag { board[0][0], board[1][1], board[2][2] };
        if (all_of(diag.begin(), diag.end(), [&](int el) { return el == who; })) {
            return true;
        }

        vector<int> rev_diag { board[2][0], board[1][1], board[0][2] };
        if (all_of(rev_diag.begin(), rev_diag.end(), [&](int el) { return el == who; })) {
            return true;
        }

        return false;
    }
};
// @lc code=end
