/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *fast = head->next->next, *slow = head->next;
        while (fast != slow) {
            if (fast == nullptr) { return nullptr; }
            fast = fast->next;
            if (fast == nullptr) { return nullptr; }
            fast = fast->next;
            slow = slow->next;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};
// @lc code=end
