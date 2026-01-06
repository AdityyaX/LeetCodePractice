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
/*
I was good at intution for this */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int maxVal = INT_MIN;
        int maxLevel = 1;
        ;
        int level = 1;
        while (!q.empty()) {
            int siz = q.size();
            int sum = 0;
            for (int i = 0; i < siz; i++) {
                TreeNode* TopElement = q.front();
                q.pop();
                TreeNode* leftElement = TopElement->left;
                TreeNode* rightElement = TopElement->right;
                if (leftElement) {
                    q.push(leftElement);
                }
                if (rightElement) {
                    q.push(rightElement);
                }
                sum += TopElement->val;
            }

            if (sum > maxVal) {
                maxVal = sum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};