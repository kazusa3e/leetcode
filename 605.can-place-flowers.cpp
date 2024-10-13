/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (auto iter = flowerbed.begin(); iter != flowerbed.end(); ++iter) {
            bool a = (iter == flowerbed.begin()) ? true : (*(iter - 1) == 0),
                b = *iter == 0,
                c = (iter == flowerbed.end() - 1) ? true : (*(iter + 1) == 0);
            if (a && b && c) {
                n -= 1; *iter = 1;
            }
        }
        return n <= 0;
    }
};
// @lc code=end
