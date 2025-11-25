class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, maxi = 0;
        vector<int> freq(128, 0); 

        for (int j = 0; j < s.size(); j++) {
            char ch = s[j];
            freq[ch]++;

            while (freq[ch] > 1) {
                freq[s[i]]--; 
                i++;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};
