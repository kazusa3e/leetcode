/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &v1, const vector<int> &v2) {
            if (v1[0] > v2[0]) return true;
            else if (v1[0] < v2[0]) return false;
            else if (v1[1] < v2[1]) return true;
            return false;
        });
        vector<vector<int>> ret;
        for (const auto &el : people) {
            ret.insert(ret.begin() + el[1], el);
        }
        return ret;
    }
};
// @lc code=end
