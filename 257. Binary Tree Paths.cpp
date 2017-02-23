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
    string createStrWithArrow(int num) {
        return "->" + to_string(num);
    }
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }
    void _binaryTreePaths(TreeNode *node, string pathUntilNow, vector<string> & results) {
        if (!node) return;
        
        pathUntilNow += createStrWithArrow(node->val);
        
        if (isLeaf(node)) {
            results.push_back(pathUntilNow);
        }
        else {
            _binaryTreePaths(node->left, pathUntilNow, results);
            _binaryTreePaths(node->right, pathUntilNow, results);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        
        if (!root) {
            // do nothing
        }
        else if (isLeaf(root)) {
            results.push_back(to_string(root->val));
        }
        else {
            _binaryTreePaths(root->left, to_string(root->val), results);
            _binaryTreePaths(root->right, to_string(root->val), results);
        }
        
        return results;
    }
};