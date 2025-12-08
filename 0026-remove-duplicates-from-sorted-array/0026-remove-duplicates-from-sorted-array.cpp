class Solution {
    /*
    here we take two pointers and iterate and get tha value */
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        int m = 0;
        while (m < nums.size()) {
            nums[n] = nums[m];
            while ((m < nums.size() && nums[n] == nums[m]))
                m++;
            n++;
        }
        return n;
    }
};