class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxlen = 0;
        vector<int> freq(128, 0);
        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;
            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};