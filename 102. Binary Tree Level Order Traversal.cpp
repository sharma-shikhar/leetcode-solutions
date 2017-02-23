/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> results;
        vector<int> buf;
        
        if (root) {
            q.push(root);
            q.push(nullptr); //marker ending this (root) level
        }
        
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t) {
                buf.push_back(t->val);
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            else { // we reached marker node // marks the end of a level
                results.push_back(buf);
                buf.resize(0);
                
                if (!q.empty())
                    q.push(nullptr); // add another marker signifying the end of the children's level
            }
        }
        
        return results;
    }
};