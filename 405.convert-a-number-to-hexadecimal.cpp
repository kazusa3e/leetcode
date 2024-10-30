/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start

#include <string>
#include <cstdint>
#include <deque>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        uint32_t n = num;
        char m[] = {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
        };
        deque<char> s;
        while (n != 0) {
            s.push_front(m[n % 16]); n /= 16;
        }
        return string { s.begin(), s.end() };
    }
};
// @lc code=end
