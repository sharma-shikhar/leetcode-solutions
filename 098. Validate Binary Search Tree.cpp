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
    bool _isValidBST(TreeNode* root, long min, long max) {
        if (!root)
            return true;
        
        return min < root->val &&
               root->val < max &&
               _isValidBST(root->left, min, root->val) &&
               _isValidBST(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());  
    }
};