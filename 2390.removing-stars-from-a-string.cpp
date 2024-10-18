/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start

#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        deque<char> st;
        for (auto ch : s) {
            if (ch != '*') st.push_back(ch);
            else {
                if (!st.empty()) st.pop_back();
            }
        }
        return { st.begin(), st.end() };
    }
};
// @lc code=end
