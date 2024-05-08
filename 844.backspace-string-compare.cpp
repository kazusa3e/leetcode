/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        handleString(std::move(s));
        handleString(std::move(t));
        auto si = s.begin(), ti = t.begin();
        for (;
             si != s.end() && ti != t.end() && *si == *ti;
             ++si, ++ti) {
        }
        if (si == s.end() && ti == t.end()) {
            return true;
        }
        return false;
    }
    void handleString(std::string &&str) {
        auto rptr = str.begin(), wptr = str.begin();
        while (rptr != str.end()) {
            if (*rptr == '#') {
                wptr = (wptr == str.begin()) ? wptr : --wptr;
            } else {
                *wptr = *rptr;
                wptr += 1;
            }
            rptr += 1;
        }
        str.erase(wptr, str.end());
    }
};
// @lc code=end
