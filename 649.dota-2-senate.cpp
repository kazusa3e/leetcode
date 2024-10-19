/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start

#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<unsigned> rad, dir;
        unsigned n = 1;
        for_each(senate.begin(), senate.end(), [&rad, &dir, &n](char ch) {
            (ch == 'R') ? rad.push(n++) : dir.push(n++);
        });
        while (!rad.empty() && !dir.empty()) {
            auto r = rad.front(), d = dir.front();
            rad.pop(); dir.pop();
            (r < d) ? rad.push(n++) : dir.push(n++);
        }
        return (rad.empty()) ? "Dire" : "Radiant";
    }
};
// @lc code=end
