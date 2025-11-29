class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        vector<int> charMap(26, 0);
        int maxFreq = INT_MIN;
        int result = 0;

        for (int j = 0; j < s.size(); j++) {
            charMap[s[j] - 'A']++;
            maxFreq = max(maxFreq, charMap[s[j] - 'A']);

            while ((j - i + 1) - maxFreq > k) {
                charMap[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};