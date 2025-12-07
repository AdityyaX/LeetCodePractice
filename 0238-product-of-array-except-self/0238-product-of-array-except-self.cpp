class Solution {
public:
    /*
    what each index value of prefix and postfix array represent here is product
    if number before and after them respectively*/
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> result(n, 1);
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = nums[i + 1] * postfix[i + 1];
        }
        for (int i = 0; i < n; i++) {
            result[i] = postfix[i] * prefix[i];
        }
        return result;
    }
};