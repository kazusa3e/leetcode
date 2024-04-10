/*
 * @lc app=leetcode id=941 lang=java
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
    public boolean validMountainArray(int[] arr) {
        if (arr.length < 3) return false;
        int maxDex = -1;
        for (int ix = 1; ix != arr.length && maxDex == -1; ++ix) {
            if (arr[ix] > arr[ix - 1]) continue;
            else if (arr[ix] == arr[ix - 1]) return false;
            else { maxDex = ix - 1; break; }
        }
        if (maxDex == 0) return false;
        if (maxDex == -1) return false;
        if (maxDex == arr.length - 1) return false;
        for (int ix = maxDex + 1; ix != arr.length; ++ix) {
            if (arr[ix] < arr[ix - 1]) continue;
            else if (arr[ix] == arr[ix - 1]) return false;
            else return false;
        }
        return true;
    }
}
// @lc code=end

