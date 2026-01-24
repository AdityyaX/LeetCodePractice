/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int leftTree = helper(root->left);
        int rightTree = helper(root->right);
        if (leftTree == -1 || rightTree == -1 ||
            abs(leftTree - rightTree) > 1) {
            return -1;
        }
        return 1 + max(leftTree, rightTree);
    }
    bool isBalanced(TreeNode* root) {
        int val = helper(root);
        return val != -1;
    }
};