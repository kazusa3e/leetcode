/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string interpret(string& command) {
        auto r = command.begin(), w = command.begin();
        while (r != command.end()) {
            if (*r == 'G') {
                *(w++) = *r++;
            } else if (*r == '(' && *(r + 1) == ')') {
                *(w++) = 'o'; r += 2;
            } else {
                *(w++) = 'a'; *(w++) = 'l';
                r += 4;
            }
        }
        command.erase(w, command.end());
        return command;
    }
};
// @lc code=end
