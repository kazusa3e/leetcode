/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start

#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(nums1.size(), -1);
        map<int, int> m;
        stack<unsigned> st;
        for (auto iter = nums2.begin(); iter != nums2.end(); ++iter) {
            while (!st.empty() && *iter > nums2[st.top()]) {
                auto idx = st.top(); st.pop();
                m[nums2[idx]] = *iter;
            }
            st.push(iter - nums2.begin());
        }
        for (auto iter = nums1.begin(); iter != nums1.end(); ++iter) {
            if (auto pos = m.find(*iter); pos != m.end()) {
                ret[iter - nums1.begin()] = pos->second;
            }
        }
        return ret;
    }
};
// @lc code=end
