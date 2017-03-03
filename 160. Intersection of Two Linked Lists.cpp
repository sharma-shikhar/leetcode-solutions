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
    pair<ListNode *, int> getLastNode(ListNode *head) {
        pair<ListNode *, int> ret = {nullptr, 0};
        
        if (!head)
            return ret;
        
        int count = 1;
        while(head->next) {
            head = head->next;
            count ++;
        }
        ret.first = head;
        ret.second = count;
        
        return ret;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        
        pair<ListNode *, int> l1 = getLastNode(headA);
        ListNode *last1 = l1.first;
        int len1 = l1.second;
        
        pair<ListNode *, int> l2 = getLastNode(headB);
        ListNode *last2 = l2.first;
        int len2 = l2.second;
        
        if (last1 != last2)
            return nullptr;
        
        ListNode *longer = l1 > l2 ? headA : headB;
        ListNode *smaller = l1 > l2 ? headB : headA;
        
        int diff = abs(len1 - len2);
        
        while (diff--)
            longer = longer->next;
        
        while (longer != smaller) {
            longer = longer->next;
            smaller = smaller->next;
        }
        
        return longer;
    }
};