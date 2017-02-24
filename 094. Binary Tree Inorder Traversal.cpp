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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> result;
        
        while (root) {
            s.push(root);
            root = root->left;
        }
        
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            result.push_back(t->val);
            if (t->right) {
                t = t->right;
                while (t) {
                    s.push(t);
                    t = t->left;
                }
            }          
        }
        
        return result;
    }
};