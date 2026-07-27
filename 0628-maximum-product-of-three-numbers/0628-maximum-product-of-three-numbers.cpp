class Solution {
    // -1 -2 -3 -3 -4
    // -4 -3 -3 -2 -1
    /*
    1 2 3 4 5
    */
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() <= 3) {
            return nums[nums.size() - 1] * nums[nums.size() - 2] *
                   nums[nums.size() - 3];
        }
        sort(nums.begin(), nums.end());
        // int neighborMin = INT_MAX;
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     int mul = nums[i] * nums[i + 1];
        //     neighborMax = max(neighborMax, mul);
        //     neighborMin = min(neighborMin, mul);
        // }
        vector<int> result;
        int startMax = nums[0] * nums[1];
        int endMax = nums[nums.size() - 1] * nums[nums.size() - 2];
        vector<int> maxVal1;
        vector<int> maxVal2;
        for (int i = 2; i <= nums.size() - 1; i++) {
            int ans1 = nums[i] * startMax;
            maxVal1.push_back(ans1);
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            int ans2 = nums[i] * endMax;
            maxVal2.push_back(ans2);
        }
        sort(maxVal1.begin(), maxVal1.end());
        sort(maxVal2.begin(), maxVal2.end());

        return max(maxVal1[maxVal1.size() - 1], maxVal2[maxVal2.size() - 1]);
    }
};