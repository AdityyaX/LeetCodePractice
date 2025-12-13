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

// here approach is BST stores element in sorted order so first traverse and
// store in an array and then return k-1 index

void inorder(TreeNode* root, vector<int>& arr) {
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k - 1];
    }
};