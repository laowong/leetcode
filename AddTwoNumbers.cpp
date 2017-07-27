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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *lastValue = NULL;
        ListNode *newValue = NULL;
        int carry = 0;
        int sum = 0;
        while (NULL != l1 && NULL != l2)
        {
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            newValue = new ListNode(sum);
            if (NULL == result)
            {
                result = newValue;
                lastValue = newValue;
            }
            else
            {
                lastValue->next = newValue;
                lastValue = newValue;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *restNode = l1;
        if (NULL == l1)
        {
            restNode = l2;
        }
        while (NULL != restNode)
        {
            sum = (restNode->val + carry) % 10;
            carry = (restNode->val + carry) / 10;
            lastValue->next = new ListNode(sum);
            lastValue = lastValue->next;
            restNode = restNode->next;
        }
        if (0 != carry)
        {
            lastValue->next = new ListNode(carry);
        }
        return result;
    }
};