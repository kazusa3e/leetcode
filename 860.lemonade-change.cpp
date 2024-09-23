/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<unsigned, unsigned> umap;
        umap[5] = 0; umap[10] = 0; umap[20] = 0;
        for (auto el : bills) {
            umap[el] += 1;
            int remain = el - 5;
            while (remain != 0) {
                if (remain >= 20 && umap[20] != 0) {
                    umap[20] -= 1; remain -= 20;
                } else if (remain >= 10 && umap[10] != 0) {
                    umap[10] -= 1; remain -= 10;
                } else if (remain >= 5 && umap[5] != 0) {
                    umap[5] -= 1; remain -= 5;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
