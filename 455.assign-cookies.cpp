/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start

#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        deque<int> gg {g.begin(), g.end()}, ss{s.begin(), s.end()};
        sort(gg.begin(), gg.end());
        sort(ss.begin(), ss.end());
        int cnt = 0;
        for (auto iter = ss.begin(); iter != ss.end(); ++iter) {
            if (gg.empty()) break;
            if (*iter >= gg.front()) {
                gg.pop_front();
                cnt += 1;
            }
        }
        return cnt;
    }
};
// @lc code=end
