class Solution {
public:
    /*
    In this we will apply binary search such that
    while(left<right)
    if(nums[right]>nums[mid] high=mid-1
    else low=mid+1*/
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};