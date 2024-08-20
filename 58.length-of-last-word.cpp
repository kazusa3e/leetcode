/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        unsigned last = 0;
        unsigned sz = 0;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == ' ') {
                last = (sz != 0) ? sz : last;
                sz = 0;
            } else {
                sz += 1;
            }
        }
        last = (sz != 0) ? sz : last;
        return last;
    }
};
// @lc code=end
