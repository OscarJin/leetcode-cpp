/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        return mergeHalfKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeHalfKLists(vector<ListNode*>& lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        if (start + 1 == end)
            return mergeTwoLists(lists[start], lists[end]);

        int mid = start + ((end - start) >> 1);
        ListNode* leftMerge = mergeHalfKLists(lists, start, mid);
        ListNode* rightMerge  = mergeHalfKLists(lists, mid + 1, end);
        return mergeTwoLists(leftMerge, rightMerge);
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        if (list1 -> val < list2 -> val)
        {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
        else
        {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }

};
// @lc code=end

