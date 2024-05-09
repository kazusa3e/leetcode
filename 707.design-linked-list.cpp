/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start

#include <memory>

class MyLinkedList {
private:
    struct LinkedListNode {
        int val;
        LinkedListNode *prev;
        LinkedListNode *next;
        LinkedListNode() = default;
        LinkedListNode(int v, LinkedListNode *p, LinkedListNode *n):
            val(v), prev(p), next(n) {}
    };

    std::unique_ptr<LinkedListNode> sentinel;
    size_t sz = 0;

public:
    MyLinkedList() {
        this->sentinel = std::make_unique<LinkedListNode>();
        this->sentinel->val = -1;
        this->sentinel->prev = this->sentinel.get();
        this->sentinel->next = this->sentinel.get();
    }

    int get(int index) {
        if (index < 0 || index >= this->sz) {
            return -1;
        }
        LinkedListNode *iter = this->sentinel->next;
        int cnt = 0;
        while (cnt != index) {
            iter = iter->next;
            cnt += 1;
        }
        return iter->val;
    }

    void addAtHead(int val) {
        LinkedListNode *node = new LinkedListNode(
            val,
            this->sentinel.get(),
            this->sentinel->next
        );
        this->sentinel->next->prev = node;
        this->sentinel->next = node;
        this->sz += 1;
    }

    void addAtTail(int val) {
        LinkedListNode *node = new LinkedListNode(
            val,
            this->sentinel->prev,
            this->sentinel.get()
        );
        this->sentinel->prev->next = node;
        this->sentinel->prev = node;
        this->sz += 1;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->sz) {
            return;
        }
        LinkedListNode *iter = this->sentinel.get();
        int cnt = 0;
        while (cnt != index) {
            iter = iter->next;
            cnt += 1;
        }
        LinkedListNode *node = new LinkedListNode(
            val,
            iter,
            iter->next
        );
        iter->next->prev = node;
        iter->next = node;
        this->sz += 1;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->sz) {
            return;
        }
        LinkedListNode *iter = this->sentinel.get();
        int cnt = 0;
        while (cnt != index) {
            iter = iter->next;
            cnt += 1;
        }
        LinkedListNode *tmp = iter->next;
        iter->next = tmp->next;
        tmp->next->prev = iter;
        delete tmp;
        this->sz -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
