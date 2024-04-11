/*
 * @lc app=leetcode id=448 lang=java
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        for (int ix = 0; ix != nums.length; ++ix) {
            while (nums[ix] != ix + 1) {
                if (nums[ix] == nums[nums[ix] - 1]) break;
                swap(nums, ix, nums[ix] - 1);
            }
        }
        for (int ix = 0; ix != nums.length; ++ix) {
            if (nums[ix] != ix + 1) { ret.add(ix + 1); }
        }
        return ret;
    }
}
// @lc code=end

