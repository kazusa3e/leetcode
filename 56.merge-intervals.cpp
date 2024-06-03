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
            return v1[0] < v2[0];
        });
        auto iter = intervals.begin();
        while (iter < prev(intervals.end())) {
            if ((*iter)[1] >= (*(iter + 1))[0]) {
                (*iter)[1] = max((*iter)[1], (*(iter + 1))[1]);
                iter = intervals.erase(iter + 1);
                iter = prev(iter);
            } else {
                iter = iter + 1;
            }
        }
        return intervals;
    }
};
// @lc code=end
