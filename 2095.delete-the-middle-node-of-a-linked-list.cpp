/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            // delete head; return nullptr;
            return nullptr;
        }
        auto slow = head, fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; fast = fast->next->next;
        }
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return head;
    }
};
// @lc code=end
