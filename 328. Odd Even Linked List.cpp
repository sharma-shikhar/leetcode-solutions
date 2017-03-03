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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        
        ListNode *odd, *even;
        odd = oddHead;
        even = evenHead;
        
        ListNode *cur = head->next->next;
        int index = 3;
        while (cur) {
            if (index % 2 == 1) {
                odd->next = cur;
                odd = odd->next;
            } else {
                even->next = cur;
                even = even->next;
            }
            cur = cur->next;
            index++;
        }
        even->next = nullptr;
        odd->next = evenHead;
        return oddHead;
    }
};