/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<unsigned> st;
        for (auto iter = temperatures.begin(); iter != temperatures.end(); ++iter) {
            while (!st.empty() && *iter > temperatures[st.top()]) {
                auto idx = st.top(); st.pop();
                ret[idx] = iter - temperatures.begin() - idx;
            }
            st.push(iter - temperatures.begin());
        }
        return ret;
    }
};
// @lc code=end
