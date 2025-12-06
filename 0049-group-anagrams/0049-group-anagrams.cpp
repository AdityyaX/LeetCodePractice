class Solution {
    /*
    here my intution is lets group string to an array by sorting them in
    hash map and return the  hashmap.second*/
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        vector<vector<string>> result;
        for (string str : strs) {
            string sortedString = str;
            sort(sortedString.begin(), sortedString.end());
            anagram[sortedString].push_back(str);
        }
        for (auto& arr : anagram) {
            result.push_back(arr.second);
        }
        return result;
    }
};