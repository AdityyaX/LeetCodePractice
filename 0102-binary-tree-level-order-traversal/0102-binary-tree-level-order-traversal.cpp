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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> currentlevel;
            for (int i = 0; i < len; i++) {
                TreeNode* frontValue = q.front();
                int value = frontValue->val;
                q.pop();
                currentlevel.push_back(value);
                if (frontValue->left)
                    q.push(frontValue->left);
                if (frontValue->right)
                    q.push(frontValue->right);
            }

            result.push_back(currentlevel);
        }
        return result;
    }
};