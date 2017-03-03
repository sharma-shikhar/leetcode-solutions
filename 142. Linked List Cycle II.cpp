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
    ListNode *getInloopNode(ListNode *head) {
        if (!head)
            return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (slow && fast && fast->next) {
            if (slow == fast)
                return slow;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }

    int getLoopLength(ListNode *head) {
        int count = 1;
        if (head->next == head)
            return count;

        ListNode *n = head->next;
        while (n != head) {
            n = n->next;
            count++;
        }
        return count;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *inloopNode = getInloopNode(head);
        if (!inloopNode)
            return inloopNode;
        
        int loopLength = getLoopLength(inloopNode);
        
        ListNode *ahead = head;
        while (loopLength--)
            ahead = ahead->next;
            
        while (head != ahead) {
            head = head->next;
            ahead = ahead->next;
        }
        return head;
    }
};