/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') { st.push(')'); continue; }
            if (ch == '[') { st.push(']'); continue; }
            if (ch == '{') { st.push('}'); continue; }
            if (st.empty()) { return false; }
            if (st.top() != ch) { return false; }
            st.pop();
        }
        return st.empty();
    }
};
// @lc code=end
