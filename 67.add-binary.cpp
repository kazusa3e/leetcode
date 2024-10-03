/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#include <string>
#include <list>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        list<char> ret;
        auto ai = a.rbegin(), bi = b.rbegin();
        while (ai != a.rend() && bi != b.rend()) {
            // 0, 1, 2, 3
            int val = (*ai - '0') + (*bi - '0') + carry;
            carry = 0;
            if (val == 1 || val == 3) {
                ret.push_front('1');
            } else {
                ret.push_front('0');
            }
            if (val == 2 || val == 3) carry = 1;
            ++ai; ++bi;
        }

        while (ai != a.rend()) {
            // 0, 1, 2
            int val = (*ai - '0') + carry;
            carry = 0;
            if (val == 0 || val == 2) {
                ret.push_front('0');
            } else {
                ret.push_front('1');
            }
            if (val == 2) carry = 1;
            ++ai;
        }
        while (bi != b.rend()) {
            // 0, 1, 2
            int val = (*bi - '0') + carry;
            carry = 0;
            if (val == 0 || val == 2) {
                ret.push_front('0');
            } else {
                ret.push_front('1');
            }
            if (val == 2) carry = 1;
            ++bi;
        }
        if (carry) ret.push_front('1');
        return string {ret.begin(), ret.end()};
    }
};
// @lc code=end
