/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto token: tokens) {
            if (isOperator(token)) {
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                if (token == "+") { st.push(to_string(a + b)); }
                if (token == "-") { st.push(to_string(a - b)); }
                if (token == "*") { st.push(to_string(a * b)); }
                if (token == "/") { st.push(to_string(a / b)); }
            } else {
                st.push(token);
            }
        }
        return stoi(st.top());
    }
    bool isOperator(const string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};
// @lc code=end
