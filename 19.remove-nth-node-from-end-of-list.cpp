/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode virtualHead = ListNode(0, head);
        ListNode* preSlow = &virtualHead;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr)
        {
            if (n <= 0)
            {
                preSlow = slow;
                slow = slow -> next;
            }
            n--;
            fast = fast -> next;
        }

        preSlow -> next = slow -> next;
        return virtualHead.next;
    }
};
// @lc code=end

