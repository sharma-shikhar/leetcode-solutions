/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
            
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(nullptr);
        TreeLinkNode *prev = nullptr;
        
        while (!q.empty()) {
            TreeLinkNode *cur = q.front(); q.pop();
            if (prev)
                prev->next = cur;
            
            prev = cur;
            
            if (cur) { // still on the same level
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            else if (!q.empty()) { // cur==nullptr and q is not empty
                q.push(nullptr);
            }
        }
    }
};