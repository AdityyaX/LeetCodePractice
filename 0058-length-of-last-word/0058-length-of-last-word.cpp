class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int len = s.length() - 1;
        while (len >= 0 && s[len] == ' ')
            len--;

        while (len >= 0 && s[len] != ' ') {
            i++;
            len--;
        }
        return i;
    }
};