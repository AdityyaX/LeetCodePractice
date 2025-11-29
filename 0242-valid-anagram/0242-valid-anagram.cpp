class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> alph(26, 0);
        for (int i = 0; i < s.length(); i++) {
            alph[s[i] - 'a']++;
            alph[t[i] - 'a']--;
        }

        for (int i = 0; i < alph.size(); i++) {

            if (alph[i] != 0) {
                return false;
            }
        }
        return true;
    }
};