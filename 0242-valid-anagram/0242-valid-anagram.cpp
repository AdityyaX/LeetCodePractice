class Solution {
/*
brute force can be sort both of them and match the,
we can use two hasmaps as well but best approach will be 
this can be the one of the best approach we can also utilie vector for this
*/
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mpp[s[i]] != 0)
                return false;
        }
        return true;
    }
};