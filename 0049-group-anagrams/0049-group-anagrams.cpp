class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            mpp[sortedStr].push_back(str);
        }
        for (auto mp : mpp) {
            result.push_back(mp.second);
        }
        return result;
    }
};