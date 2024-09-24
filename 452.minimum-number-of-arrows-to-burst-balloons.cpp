/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return less {}(v1[0], v2[0]);
        });
        int cnt = 1;
        for (int ix = 1; ix != points.size(); ++ix) {
            if (points[ix][0] > points[ix - 1][1]) {
                cnt += 1;
            } else {
                points[ix][1] = min(points[ix][1], points[ix - 1][1]);
            }
        }
        return cnt;
    }
};
// @lc code=end
