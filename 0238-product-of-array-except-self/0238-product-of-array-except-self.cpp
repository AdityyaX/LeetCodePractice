class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> result(n, 1);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            cout << prefix[i] << endl;
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
            // cout << suffix[i] << endl;
        }
        for (int i = 0; i < n; i++) {
            result[i] = suffix[i] * prefix[i];

            // // 1 2 6 24
            // // 24 24 12 4
            // 24 12 8 6
        }
        return result;
    }
};