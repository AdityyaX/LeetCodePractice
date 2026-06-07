class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxlen = 0;
        vector<int> stringMap(128, 0);
        for (int j = 0; j < s.size(); j++) {
            stringMap[s[j]]++;
            while (stringMap[s[j]] > 1) {
                stringMap[s[i]]--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};