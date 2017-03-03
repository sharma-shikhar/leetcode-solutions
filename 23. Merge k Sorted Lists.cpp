/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ListNodeExtra {
public:
    ListNode *n;
    int index;
    ListNodeExtra(ListNode *n, int index) : n(n), index(index) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& _lists) {
        vector<ListNode *> lists = _lists;
        
        auto cmp = [] (ListNodeExtra & l1, ListNodeExtra & l2) -> bool {
            return (l1.n)->val > (l2.n)->val;
        };
        
        priority_queue<ListNodeExtra, vector<ListNodeExtra>, decltype(cmp)> minHeap(cmp);
        
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                minHeap.push(ListNodeExtra(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }
        
        ListNode *resHead = new ListNode(0); // dummy
        ListNode *res = resHead;
        
        while (!minHeap.empty()) {
            ListNodeExtra ln = minHeap.top(); minHeap.pop();
            ListNode *n = ln.n;
            int index = ln.index;
            
            res->next = n;
            res = n;
            
            if (lists[index]) {
                minHeap.push(ListNodeExtra(lists[index], index));
                lists[index] = lists[index]->next;
            }
            
        }
        
        res = resHead->next;
        delete resHead; // dummy
        return res;
    }
};