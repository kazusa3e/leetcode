/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class KthLargest {
private:
    vector<int> nums_;
    int k_;

public:
    KthLargest(int k, vector<int>& nums) {
        nums_ = nums;
        sort(nums_.begin(), nums_.end(), greater {});
        k_ = k;
    }
    
    int add(int val) {
        auto pos = lower_bound(nums_.begin(), nums_.end(), val, greater {});
        nums_.insert(pos, val);
        return nums_[k_ - 1];
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
