/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> nums;    // b, a
        transform(nums1.begin(), nums1.end(), nums2.begin(), back_inserter(nums), [](int a, int b) {
            return make_pair(b, a);
        });
        sort(nums.begin(), nums.end(), greater {});

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum_a = 0, ans = 0;
        for (const auto &[b, a] : nums) {
            sum_a += a; pq.push(a);
            if (pq.size() > k) {
                sum_a -= pq.top(); pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, b * sum_a);
            }
        }
        return ans;
    }
};
// @lc code=end
