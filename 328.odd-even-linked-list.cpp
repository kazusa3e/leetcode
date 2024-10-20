/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        auto tail_of_odd = head;
        ListNode dummy_node { -1, nullptr }, *dummy = &dummy_node, *tail_of_even = dummy;
        auto append_even = [&](ListNode *node) {
            tail_of_even->next = node;
            node->next = nullptr;
            tail_of_even = tail_of_even->next;
        };
        auto append_odd = [&](ListNode *node) {
            tail_of_odd->next = node;
            node->next = nullptr;
            tail_of_odd = tail_of_odd->next;
        };
        auto iter = head->next; unsigned ix = 2;
        while (iter != nullptr) {
            auto next = iter->next;
            if (ix % 2 == 0) {
                append_even(iter);
            } else {
                append_odd(iter);
            }
            iter = next;
            ix += 1;
        }
        tail_of_odd->next = dummy->next;
        return head;
    }
};
// @lc code=end
