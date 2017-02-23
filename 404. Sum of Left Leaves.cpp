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
    bool isLeaf(TreeNode *n) {
        return !n->left && !n->right;
    }
    void _sumOfLeftLeaves(TreeNode *n, int & sum) {
        if (n->left) {
            if (isLeaf(n->left))
                sum += n->left->val;
            else 
                _sumOfLeftLeaves(n->left, sum);
        }
        
        if (n->right)
            _sumOfLeftLeaves(n->right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root)
            _sumOfLeftLeaves(root, sum);
        return sum;
    }
};