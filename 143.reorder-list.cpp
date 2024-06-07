/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = slow, *curr = slow->next;
        while (curr != nullptr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        slow->next = nullptr;

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (head != nullptr && prev != nullptr) {
            ListNode *t1 = head->next, *t2 = prev->next;
            tail->next = head;
            tail->next->next = prev;
            tail = tail->next->next;
            head = t1;
            prev = t2;
        }
        tail->next = nullptr;
        head = dummy->next;
        delete dummy;
    }
};
// @lc code=end
