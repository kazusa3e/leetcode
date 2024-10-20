/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        for (auto iter = head; iter != nullptr; iter = iter->next) { nums.push_back(iter->val); }
        transform(nums.begin(), nums.begin() + nums.size() / 2, nums.rbegin(), nums.begin(), plus {});
        return *max_element(nums.begin(), nums.end());
    }
};
// @lc code=end
