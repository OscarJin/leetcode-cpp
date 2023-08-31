// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k ==  0)
            return head;

        ListNode newHead = ListNode(0, head);
        int len = 0;
        ListNode* cur = &newHead;
        while (cur -> next != nullptr)
        {
            len++;
            cur = cur -> next;
        }
        if (k % len == 0)
            return head;
        
        cur -> next = head;
        cur = &newHead;
        for (int i = len - k % len; i > 0; i--)
            cur = cur -> next;
        
        ListNode res = ListNode(0, cur -> next);
        cur -> next = nullptr;
        return res.next;
    }
};
// @lc code=end

