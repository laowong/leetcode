/*
 * ÌâÄ¿£ºMerge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Á´½Ó£ºhttps://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *Head = NULL, *curNode1 = l1, *curNode2 = l2, *minNode = NULL;
        ListNode **preNext = &Head;
        while (NULL != curNode1 && NULL != curNode2)
        {
            if (curNode1->val < curNode2->val)
            {
                minNode = curNode1;
                curNode1 = curNode1->next;
            }
            else
            {
                minNode = curNode2;
                curNode2 = curNode2->next;
            }
            *preNext = new ListNode(minNode->val);
            preNext = &((*preNext)->next);
        }
        while (NULL != curNode1)
        {
            *preNext = new ListNode(curNode1->val);
            preNext = &((*preNext)->next);
            curNode1 = curNode1->next;
        }
        while (NULL != curNode2)
        {
            *preNext = new ListNode(curNode2->val);
            preNext = &((*preNext)->next);
            curNode2 = curNode2->next;
        }
        return Head;
    }
};