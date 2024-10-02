/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        sort(coordinates.begin(), coordinates.end(), [](const vector<int> &v1, const vector<int> &v2) {
            if (v1[0] != v2[0]) return less {} (v1[0], v2[0]);
            return less {} (v1[1], v2[1]);
        });
        int a = coordinates[1][1] - coordinates[0][1],
            b = coordinates[1][0] - coordinates[0][0];
        for (auto iter = coordinates.begin(); iter != coordinates.end() - 1; ++iter) {
            auto delta_x = (*(iter + 1))[0] - (*iter)[0],
                delta_y = (*(iter + 1))[1] - (*iter)[1];
            if (a * delta_x != b * delta_y) return false;
        }
        return true;
    }
};
// @lc code=end
