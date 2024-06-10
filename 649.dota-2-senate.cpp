/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        auto iter = senate.begin();
        while (true) {
            char opposite = (*iter == 'R') ? 'D' : 'R';
            auto diff = distance(senate.begin(), iter);
            if (auto rpos = find(iter + 1, senate.end(), opposite); rpos != senate.end()) {
                senate.erase(rpos);
                iter = senate.begin() + diff + 1;
            } else if (auto lpos = find(senate.begin(), iter, opposite); lpos != iter) {
                senate.erase(lpos);
                iter = senate.begin() + diff;
            } else {
                return (*iter == 'R') ? "Radiant" : "Dire";
            }
            if (iter == senate.end()) iter = senate.begin();
        }
        return "";
    }
};
// @lc code=end
