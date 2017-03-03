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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left, *leftBegin;
        ListNode *right, *rightBegin;
        
        // int with dummy nodes to make later code easier
        left = leftBegin = new ListNode(-1);
        right = rightBegin = new ListNode(-1);
        
        ListNode *n = head;
        while (n) {
            if (n->val < x) {
                // add to left list
                left->next = n;
                left = left->next;
            }
            else {
                // add to right list
                right->next = n;
                right = right->next;
            }
            n = n->next;
        }
        
        // now, combine left and right
        if (rightBegin->next) {
            left->next = rightBegin->next;
            right->next = NULL;
        }
        
        left = leftBegin->next;
        
        delete leftBegin;
        delete rightBegin;
        
        return left;
    }
};