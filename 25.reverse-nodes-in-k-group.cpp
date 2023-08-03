/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pt = head;
        
        // move pt k steps forward
        for (int i = 0; i < k; i++)
        {
            if (pt == nullptr)
                return head;
            pt = pt -> next;
        }

        ListNode* newHead = reverse(head, pt);
        head -> next = reverseKGroup(pt, k);
        return newHead;
    }

private:
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        while (first != last)
        {
            ListNode* tmp = first -> next;
            first -> next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }
};
// @lc code=end

