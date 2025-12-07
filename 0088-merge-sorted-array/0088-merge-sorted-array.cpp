class Solution {
public:
    /*
    brute force can be lets add second array in first and the sort the first
    array*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());

        return;
    }
};