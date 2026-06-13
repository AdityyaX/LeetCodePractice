class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto mp : mpp) {
            if (mp.second > n / 3) {
                st.insert(mp.first);
            }
        }
        for (int s : st) {
            ans.push_back(s);
        }
        return ans;
    }
};