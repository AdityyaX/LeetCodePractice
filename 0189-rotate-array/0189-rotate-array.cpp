class Solution {
public:
    /*
    1st: and brute force approach can be lets store k element in another array
    and then add them again in the returned array 2nd approach:
    */
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};