class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n + 1, 0);
        vector<int> rightSum(n + 1, 0);
        vector<int> result(n, 0);
        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            result[i] = abs(leftSum[i] - rightSum[i]);
        }
        return result;
    }
};

// 10 4 8 3 0 10 14 22 25 25 15 11 3 0