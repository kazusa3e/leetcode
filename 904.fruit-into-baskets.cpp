/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 1;
        map<int, int> basket;   // type -> count
        int maxCnt = 0;
        basket[fruits.at(l)] = 1;
        while (r <= fruits.size()) {
            while (basket.size() > 2) {
                basket[fruits.at(l)] -= 1;
                if (basket[fruits.at(l)] == 0) {
                    basket.erase(fruits.at(l));
                }
                l += 1;
            }
            maxCnt = max(maxCnt, r - l);
            if (r == fruits.size()) {
                break;
            }
            basket[fruits.at(r)] += 1;
            r += 1;
        }
        return maxCnt;
    }
};
// @lc code=end
