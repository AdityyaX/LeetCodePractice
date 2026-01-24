class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = height[0];
        for (int j = 1; j < n; j++) {
            leftMax[j] = max(leftMax[j - 1], height[j]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int k = n - 2; k >= 0; k--) {
            rightMax[k] = max(rightMax[k + 1], height[k]);
        }
        for (int m = 0; m < n; m++) {
            res += min(leftMax[m], rightMax[m]) - height[m];
        }

        return res;
    }
};