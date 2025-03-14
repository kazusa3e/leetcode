/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode dummy { -1, head };
        auto slow = &dummy, fast = &dummy;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end
