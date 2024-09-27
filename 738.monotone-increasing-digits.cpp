/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start

#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        auto digits = splitDigits(n);
        if (digits.size() == 1) return n;
        for (auto iter = digits.end() - 2; iter >= digits.begin(); --iter) {
            if (*iter > *(iter + 1)) {
                *iter -= 1;
                fill(iter + 1, digits.end(), 9);
            }
        }
        return buildNumberFromDigits(digits);
    }

    int buildNumberFromDigits(deque<int> &digits) {
        int ret = 0;
        while (!digits.empty()) {
            ret *= 10;
            ret += digits.front();
            digits.pop_front();
        }
        return ret;
    }

    deque<int> splitDigits(int n) {
        deque<int> ret;
        while (n != 0) {
            ret.push_front(n % 10);
            n /= 10;
        }
        return ret;
    }
};
// @lc code=end
