/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode h {-1, head};
        ListNode *dummy = &h;
        ListNode *iter = dummy;
        while (iter->next != nullptr) {
            if (iter->next->val == val) {
                ListNode *tmp = iter->next;
                iter->next = iter->next->next;
                delete tmp;
            } else {
                iter = iter->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
