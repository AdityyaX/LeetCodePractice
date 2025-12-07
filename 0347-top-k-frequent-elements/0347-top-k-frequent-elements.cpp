class Solution {
public:
    /*
    here brute force approach which i can think of is creating a hashmap
    and then store {hashmap.second , hashmap.first } in an array of pair and
    then create a vector till k return the result
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> result;
        vector<pair<int, int>> freqMap;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto& freq : mpp) {
            freqMap.push_back({freq.second, freq.first});
        }
        sort(freqMap.rbegin(), freqMap.rend());
        for (int i = 0; i < k; i++) {
            result.push_back(freqMap[i].second);
        }
        return result;
    }
};