class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                nums[index] = num;
                index++;
            }
        }
        return index;
    }
};