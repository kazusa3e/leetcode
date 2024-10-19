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
        unsigned curr_times = 0;
        string curr_pattern = "";
        stack<unsigned> st_times;
        stack<string> st_patterns;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == '[') {
                st_times.push(curr_times);
                st_patterns.push(curr_pattern);
                curr_times = 0;
                curr_pattern = "";
            }
            else if (*iter == ']') {
                unsigned prev_times = st_times.top();
                string prev_pattern = st_patterns.top();
                st_times.pop(); st_patterns.pop();
                string tmp;
                while (prev_times--) { tmp += curr_pattern; }
                curr_pattern = prev_pattern + tmp;
            }
            else if (isdigit(*iter)) {
                curr_times = curr_times * 10 + (*iter - '0');
            } else {
                curr_pattern += *iter;
                continue;
            }
        }
        return curr_pattern;
    }
};
// @lc code=end
