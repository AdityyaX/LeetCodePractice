class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int n = s.size();
        unordered_map<char, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        for (auto mp : mpp) {
            if (mp.second != 0)
                return false;
        }
        return true;
    }
};