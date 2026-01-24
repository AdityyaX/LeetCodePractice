class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            res = max(res, area);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};