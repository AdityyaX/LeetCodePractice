class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        int area = 0;
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }

        for (int i = 0; i < n; i++) {
            area += min(rightMax[i], leftMax[i]) - height[i];
        }
        return area;
    }
};