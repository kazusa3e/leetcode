/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unsigned sum = 0;
        for (auto iter = s.begin(); iter != s.end();) {
            if (*iter == 'M') { sum += 1000; iter += 1; }
            if (*iter == 'D') { sum += 500; iter += 1; }
            if (*iter == 'C') {
                if (iter + 1 == s.end()) { sum += 100; break; }
                else if (*(iter + 1) == 'D') { sum += 400; iter += 2; }
                else if (*(iter + 1) == 'M') { sum += 900; iter += 2; }
                else { sum += 100; iter += 1; }
            }
            if (*iter == 'L') { sum += 50; iter += 1; }
            if (*iter == 'X') {
                if (iter + 1 == s.end()) { sum += 10; break; }
                else if (*(iter + 1) == 'L') { sum += 40; iter += 2; }
                else if (*(iter + 1) == 'C') { sum += 90; iter += 2; }
                else { sum += 10; iter += 1; }
            }
            if (*iter == 'V') { sum += 5; iter += 1; }
            if (*iter == 'I') {
                if (iter + 1 == s.end()) { sum += 1; break; }
                else if (*(iter + 1) == 'V') { sum += 4; iter += 2; }
                else if (*(iter + 1) == 'X') { sum += 9; iter += 2; }
                else { sum += 1; iter += 1; }
            }
        }
        return sum;
    }
};
// @lc code=end
