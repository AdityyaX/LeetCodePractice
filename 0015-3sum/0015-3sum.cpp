class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum > 0) {
                    r--;
                } 
                else if (sum < 0) {
                    l++;
                } 
                else {
                    res.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
