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
    ListNode* mergeKLists(vector<ListNode*>& _lists) {
        vector<ListNode *> lists = _lists;
        
        auto cmp = [] (pair<ListNode *, int> & p1, pair<ListNode *, int> & p2) -> bool {
            return (p1.first)->val > (p2.first)->val;
        };
        
        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, decltype(cmp)> minHeap(cmp);
        
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                minHeap.push(make_pair(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }
        
        ListNode *resHead = new ListNode(0); // dummy
        ListNode *res = resHead;
        
        while (!minHeap.empty()) {
            pair<ListNode *, int> p = minHeap.top(); minHeap.pop();
            ListNode *n = p.first;
            int index = p.second;
            
            res->next = n;
            res = n;
            
            if (lists[index]) {
                minHeap.push(make_pair(lists[index], index));
                lists[index] = lists[index]->next;
            }
        }
        
        res = resHead->next;
        delete resHead; // dummy
        return res;
    }
};