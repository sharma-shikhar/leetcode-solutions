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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mergedHead = new ListNode(-1); // dummy
        ListNode *merged = mergedHead;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                merged->next = l1;
                merged = merged->next;
                l1 = l1->next;
            }
            else {
                merged->next = l2;
                merged = merged->next;
                l2 = l2->next;
            }
        }
        
        while (l1) {
            merged->next = l1;
            merged = merged->next;
            l1 = l1->next;
        }
        while (l2) {
            merged->next = l2;
            merged = merged->next;
            l2 = l2->next;
        }
        
        merged = mergedHead->next;
        delete mergedHead;
        return merged;
    }
};