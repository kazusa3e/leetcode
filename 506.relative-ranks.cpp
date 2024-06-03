/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ret;
        if (score.empty()) return ret;

        using score_t = int;
        using index_t = int;
        using node_t = pair<score_t, index_t>;
        auto heap_comp = [](const node_t &a, const node_t &b) {
            return a.first > b.first;
        };
        vector<node_t> heap;
        for (index_t ix = 0; ix != score.size(); ++ix) {
            heap.push_back(make_pair(score[ix], ix));
        }
        make_heap(heap.begin(), heap.end(), heap_comp);
        sort_heap(heap.begin(), heap.end(), heap_comp);

        ret.resize(score.size());
        for (auto ix = 0; ix != heap.size(); ++ix) {
            auto el = heap[ix];
            if (ix == 0) ret[el.second] = "Gold Medal";
            else if (ix == 1) ret[el.second] = "Silver Medal";
            else if (ix == 2) ret[el.second] = "Bronze Medal";
            else ret[el.second] = to_string(ix + 1);
        }
        return ret;
    }
};
// @lc code=end
