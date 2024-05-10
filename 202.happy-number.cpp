/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false;
            }
            seen.insert(n);
            n = next(n);
        }
        return true;
    }
    int next(int n) {
        int sum = 0;
        while (n != 0) {
            int lsb = n % 10;
            sum += lsb * lsb;
            n = n / 10;
        }
        return sum;
    }
};
// @lc code=end
