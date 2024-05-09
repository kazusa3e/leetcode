/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode l {-1, head};
        ListNode *dummy = &l;
        ListNode *prev = dummy->next, *curr = dummy->next->next;
        while (curr != nullptr) {
            std::swap(prev->val, curr->val);
            prev = curr->next;
            curr = (curr->next == nullptr) ? nullptr : curr->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end
