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
    ListNode* deleteDuplicates2(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        if (head->val == head->next->val) {
            while (head->next && head->val == head->next->val)
                head = head->next;
        }
        
        head->next = deleteDuplicates2(head->next);
        return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *p = nullptr;
        ListNode *newhead = head;
        ListNode *n = head;
        
        while (n && n->next) {
            
            if (n->val == n->next->val) {
                while (n && n->next && n->val == n->next->val)
                    n = n->next;
                if (p)
                    p->next = n;
                else
                    newhead = n;
            }
            else {
                p = n;
                n = n->next;
            }
        }
        
        return newhead;
        
    }
};