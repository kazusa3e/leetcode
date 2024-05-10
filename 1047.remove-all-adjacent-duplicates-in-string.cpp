/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start

#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto ch: s) {
            if (!st.empty() && st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        vector<char> vec;
        while (!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(), vec.end());
        ostringstream oss;
        copy(vec.begin(), vec.end(), ostream_iterator<char>(oss));
        return oss.str();
    }
};
// @lc code=end
