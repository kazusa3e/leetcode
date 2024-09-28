/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> pos = { 0, 0 };
        for (auto ch : moves) {
            if (ch == 'U') pos.second += 1;
            if (ch == 'D') pos.second -= 1;
            if (ch == 'L') pos.first -= 1;
            if (ch == 'R') pos.first += 1;
        }
        return (pos == pair<int, int> { 0, 0 });
    }
};
// @lc code=end
