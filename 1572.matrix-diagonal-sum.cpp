/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int acc = 0;
        for (int i = 0; i != mat.size(); ++i) {
            acc += mat[i][i]; acc += mat[i][mat.size() - i];
        }
        if (mat.size() % 2 == 1) acc -= mat[mat.size() / 2][mat.size() / 2];
        return acc;
    }
};
// @lc code=end
