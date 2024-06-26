/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1, up = n + 1L;
        while (low < up) {
            int mid = low + ((up - low) >> 1);
            int res = guess(mid);
            if (res == -1) { up = mid; }
            else if (res == 1) { low = mid + 1; }
            else return mid;
        }
        return -1;
    }
};
// @lc code=end
