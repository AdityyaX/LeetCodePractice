class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxval = INT_MIN;
        while (i < j) {
            int maxwater = (j - i) * min(height[i], height[j]);
            maxval = max(maxwater, maxval);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxval;
    }
};