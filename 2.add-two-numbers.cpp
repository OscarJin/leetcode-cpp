/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ls;
        ListNode *dump = new ListNode((int)0);
        ListNode **sum = &ls;
        int carry = 0;
        int now = 0;
        while(l1 != dump || l2 != dump || carry != 0)
        {
            now = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            *sum = new ListNode(now);
            sum = &(*sum)->next;
            if (l1->next == NULL)
                l1 = dump;
            else 
                l1 = l1->next;
            if (l2->next == NULL)
                l2 = dump;
            else
                l2 = l2->next;
        }
    delete dump;
    return ls;
    }
};
// @lc code=end

