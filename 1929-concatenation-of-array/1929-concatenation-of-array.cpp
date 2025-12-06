class Solution {
public:
/*
here intution will be simple for loop traversal just calculage size properly*/
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i <= 2 * n - 1; i++) {
            cout << i % n << endl;
            result.push_back(nums[i % n]);
        }
        return result;
    }
};