class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        vector<int> maxFreq(26, 0);
        int maxVal = 0;
        int res = 0;
        for (int j = 0; j < s.size(); j++) {
            maxFreq[s[j] - 'A']++;
            maxVal = max(maxVal, maxFreq[s[j] - 'A']);
            while (j - i + 1 - maxVal > k) {
                maxFreq[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};