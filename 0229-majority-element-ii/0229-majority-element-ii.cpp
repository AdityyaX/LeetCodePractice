class Solution {
public:
    /*
    here on approach can be using hasmap*/
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ans;
        vector<int> result;
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        for (int num : nums) {
            if (mpp[num] > n / 3) {
                ans.insert(num);
            }
        }
        for (int num : ans) {
            result.push_back(num);
        }

        return result;
    }
};