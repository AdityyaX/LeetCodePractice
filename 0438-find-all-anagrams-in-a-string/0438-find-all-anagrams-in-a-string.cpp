class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
            return result;
        vector<int> freqP(26, 0), freqW(26, 0);

        for (char c : p) {
            freqP[c - 'a']++;
        }
        int window = p.size();
        for (int i = 0; i < s.size(); i++) {
            freqW[s[i] - 'a']++;
            if (i - window >= 0) {
                freqW[s[i - window] - 'a']--;
            }
            if (freqW == freqP) {
                result.push_back(i - window + 1);
            };
        }
        return result;
    }
};