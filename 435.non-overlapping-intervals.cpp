/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return less {}(v1[1], v2[1]);
        });
        int cnt = 1;
        int end = intervals[0][1];
        for (int ix = 1; ix != intervals.size(); ++ix) {
            if (intervals[ix][0] >= end) {
                end = intervals[ix][1];
                cnt += 1;
            }
        }
        return intervals.size() - cnt;
    }
};
// @lc code=end
