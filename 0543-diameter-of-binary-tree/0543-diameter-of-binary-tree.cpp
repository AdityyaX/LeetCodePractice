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
    int diamater = 0;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int leftTree = helper(root->left);
        int rightTree = helper(root->right);
        diamater = max(diamater, leftTree + rightTree);
        return 1 + max(leftTree, rightTree);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = helper(root);
        return diamater;
    }
};