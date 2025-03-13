/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    using element_type = pair<int, unsigned>;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unsigned> umap;
        for (const auto &el : nums) ++umap[el];
        auto freq_cmp = [](const element_type &lhs, const element_type &rhs) -> bool {
            return lhs.second > rhs.second;
        };
        vector<element_type> vec { umap.cbegin(), umap.cend() };
        partial_sort(vec.begin(), vec.begin() + k, vec.end(), freq_cmp);
        vector<int> ret;
        transform(vec.cbegin(), vec.cbegin() + k, back_inserter(ret), [](const auto &e) {
            return e.first;
        });
        return ret;
    }
};
// @lc code=end
