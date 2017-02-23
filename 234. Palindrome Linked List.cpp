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

    int getLength(ListNode *n) {
        int count = 0;
        while (n) {
            count++;
            n = n->next;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int len = getLength(head);
        
        ListNode *n = head;
        for (int i=0; i<len/2; i++) {
            s.push(n->val);
            n = n->next;
        }
        
        if (len % 2)
            n = n->next;
        
        while(!s.empty()) {
            int val = s.top(); s.pop();
            if (n->val != val)
                return false;
            n = n->next;
        }
        return true;
    }
};