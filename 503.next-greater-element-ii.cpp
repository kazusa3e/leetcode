/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size() * 2, -1);
        stack<unsigned> st;
        nums.resize(nums.size() * 2);
        copy(nums.begin(), nums.begin() + nums.size() / 2, nums.begin() + nums.size() / 2);
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            while (!st.empty() && *iter > nums[st.top()]) {
                auto idx = st.top(); st.pop();
                ret[idx] = *iter;
            }
            st.push(iter - nums.begin());
        }
        ret.resize(ret.size() / 2);
        return ret;
    }
};
// @lc code=end
