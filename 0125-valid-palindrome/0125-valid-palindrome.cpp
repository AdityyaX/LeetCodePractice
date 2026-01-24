class Solution {
public:
    bool isPalindromeHelper(string s, int i) {
        int j = s.size();
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int i = 0;
        return isPalindromeHelper(s, i);
    }
};