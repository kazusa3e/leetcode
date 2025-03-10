/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ret(address.size() + 6, '\0');
        auto iter = ret.begin();
        for (const auto &ch : address) {
            if (ch == '.') {
                *(iter++) = '['; *(iter++) = '.'; *(iter++) = ']';
            } else {
                *(iter++) = ch;
            }
        }
        return ret;
    }
};
// @lc code=end
