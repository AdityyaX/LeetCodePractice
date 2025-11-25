class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        /*
        logic here iscreate a freq map whic can also store negative number 
        check there value if it is greater than x than it is a 
        beauty push it in array
        */
        int i = 0;
        vector<int> freq(101, 0);

        vector<int> ans;
        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j] + 50]++;

            if (j - i + 1 == k) {
                int count = 0;
                int beauty = 0;
                for (int val = -50; val < 0; val++) {
                    count += freq[val + 50];
                    if (count >= x) {
                        beauty = val;
                        break;
                    }
                }
                ans.push_back(beauty);

                freq[nums[i] + 50]--;
                i++;
            }
        }
        return ans;
    }
};