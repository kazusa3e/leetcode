/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    using element_type = pair<int, unsigned>;

    template <typename Comparator>
    struct frequent_comparator {
        bool operator()(const element_type &lhs, const element_type &rhs) const {
            return Comparator {} (lhs.second, rhs.second);
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unsigned> umap;
        for (const auto &el : nums) ++umap[el];
        priority_queue<element_type, vector<element_type>, frequent_comparator<greater<>>> pq;
        for (const auto &[val, freq] : umap) {
            if (pq.size() != k) {
                pq.push(make_pair(val, freq)); continue;
            }
            if (freq > pq.top().second) {
                if (pq.size() == k) pq.pop();
                pq.push(make_pair(val, freq));
            }
        }
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().first); pq.pop();
        }
        return ret;
    }
};
// @lc code=end
