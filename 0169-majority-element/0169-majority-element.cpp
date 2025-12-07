class Solution {
public:
    /*
    here we can have mulitple sortung hash map let's try this with mooore voting
    algorithm*/
    int majorityElement(vector<int>& nums) {
        int el;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                el = nums[i];
                count++;
            } else if (nums[i] == el) {
                count++;
            } else {
                count--;
            }
        }
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el)
                count1++;
        }
        if (count1 > nums.size() / 2) {
            return el;
        }

        return -1;
    }
};