/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        if (isalpha(s.front())) return 0;

        auto pos = s.cbegin();
        if (s.front() == ' ') pos = find_if_not(s.cbegin(), s.cend(), [](char ch) {
            return ch == ' ';
        });
        if (pos == s.cend()) return 0;

        bool is_negative = false;
        if (*pos == '-' || *pos == '+') {
            if (*pos == '-') is_negative = true;
            ++pos;
        }
        
        auto end = find_if_not(pos, s.cend(), [](char ch) { return isdigit(ch); });
        if (pos == end) return 0;
        long ret = (*pos - '0');
        for (auto iter = pos + 1; iter != end; ++iter) {
            ret *= 10; ret += (*iter - '0');
            if (is_negative && -ret < numeric_limits<int>::min()) return numeric_limits<int>::min();
            if (!is_negative && ret > numeric_limits<int>::max()) return numeric_limits<int>::max();
        }

        if (is_negative) ret = -ret;
        return ret;
    }
};
// @lc code=end
