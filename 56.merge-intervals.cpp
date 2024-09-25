/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return less {}(v1[0], v2[0]);
        });
        vector<vector<int>> ret;
        vector<int> curr = intervals[0];
        for (auto iter = intervals.begin() + 1; iter != intervals.end(); ++iter) {
            if ((*iter)[0] <= curr[1]) {
                curr[1] = max((*iter)[1], curr[1]);
            } else {
                ret.push_back(curr);
                curr = *iter;
            }
        }
        ret.push_back(curr);
        return ret;
    }
};
// @lc code=end
