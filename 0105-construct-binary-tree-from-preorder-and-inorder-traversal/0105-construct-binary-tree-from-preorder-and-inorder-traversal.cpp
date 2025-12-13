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
    /*
    preorder: [3,9,20,15,7],
    inorder: [9,3,15,20,7]
    map:[]
    here approach is we will get root from preorder and for that element number
    on left side is left side in preOrder is left tree nad on right side is
    right subTree
    */
    int index = 0;
    unordered_map<int, int> mpp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return helper(preorder, 0, end);
    }
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;

        int val = preorder[index];
        index++;
        TreeNode* root = new TreeNode(val);
        int mid = mpp[val];
        TreeNode* leftSubtree = helper(preorder, start, mid - 1);
        TreeNode* rightSubtree = helper(preorder, mid + 1, end);
        root->left = leftSubtree;
        root->right = rightSubtree;
        return root;
    }
};