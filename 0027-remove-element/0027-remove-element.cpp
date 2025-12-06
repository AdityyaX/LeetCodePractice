class Solution {
public:
    /*
    here brute force intution will be create a copy array and dont push value in
    it and return copy size
    second intution is two pointer approach lets move a pointer and update same
    array third app
    here o(N)time will be used*/
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};