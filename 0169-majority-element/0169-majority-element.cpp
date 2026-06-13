class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int count = 0;
        int el = nums[i];
        while (i < n) {
            if (count == 0) {
                el = nums[i];
            }
            if (nums[i] == el) {
                count++;

            } else {
                count--;
            }
            i++;
        }

        int count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                count2++;
            }
            if (count2 > n / 2) {
                return el;
            }
        }
        return -1;
    }
};