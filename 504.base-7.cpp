/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start

#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool flag = (num < 0); num = abs(num);
        deque<char> s;
        while (num != 0) {
            s.push_front((char) (num % 7) + '0'); num /= 7;
        }
        if (flag) s.push_front('-');
        return string { s.begin(), s.end() };
    }
};
// @lc code=end
