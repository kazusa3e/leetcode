/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = size(headA), sizeB = size(headB);
        ListNode *longer = (sizeA > sizeB) ? headA : headB;
        ListNode *shorter = (longer == headA) ? headB : headA;
        int diff = (sizeA > sizeB) ? sizeA - sizeB : sizeB - sizeA;
        while (diff != 0) {
            longer = longer->next;
            diff -= 1;
        }
        while (longer != nullptr && longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;
    }
    int size(ListNode *head) {
        int sz = 0;
        while (head != nullptr) {
            sz += 1;
            head = head->next;
        }
        return sz;
    }
};
// @lc code=end
