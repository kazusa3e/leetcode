/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start

#include <string>
#include <stack>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<unsigned> times;
        stack<string> patterns;
        string times_tmp;
        string ret;
        patterns.push("");
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (isdigit(*iter)) {
                times_tmp += *iter;
            } else if (*iter == '[') {
                times.push(stoi(times_tmp));
                times_tmp.clear();
                patterns.push("");
            } else if (*iter == ']') {
                unsigned t = times.top(); times.pop();
                string p = patterns.top(); patterns.pop();
                string tmp;
                while (t != 0) {
                    tmp += p;
                    t -= 1;
                }
                patterns.top() += tmp;
            } else if (isalpha(*iter)) {
                patterns.top() += *iter;
            } else {
                throw runtime_error {"error"};
            }
        }
        times_tmp = 1;
        return patterns.top();
    }
};
// @lc code=end
