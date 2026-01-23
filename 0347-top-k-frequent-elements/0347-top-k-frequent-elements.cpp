class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> arr;
        for (auto mp : mpp) {
            arr.push_back({mp.second, mp.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};