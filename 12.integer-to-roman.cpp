/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        while (num != 0) {
            if (num >= 1000) {
                ret += string (num / 1000, 'M');
                num %= 1000; continue;
            }
            if (num >= 900) {
                ret += "CM"; num -= 900; continue;
            }
            if (num >= 500) {
                ret += string(num / 500, 'D');
                num %= 500; continue;
            }
            if (num >= 400) {
                ret += "CD"; num -= 400; continue;
            }
            if (num >= 100) {
                ret += string(num / 100, 'C');
                num %= 100; continue;
            }
            if (num >= 90) {
                ret += "XC"; num -= 90; continue;
            }
            if (num >= 50) {
                ret += string(num / 50, 'L');
                num %= 50; continue;
            }
            if (num >= 40) {
                ret += "XL"; num -= 40; continue;
            }
            if (num >= 10) {
                ret += string(num / 10, 'X');
                num %= 10; continue;
            }
            if (num >= 9) {
                ret += "IX"; num -= 9; continue;
            }
            if (num >= 5) {
                ret += string(num / 5, 'V');
                num %= 5; continue;
            }
            if (num >= 4) {
                ret += "IV"; num -= 4; continue;
            }
            ret += string(num, 'I'); num = 0;
        }
        return ret;
    }
};
