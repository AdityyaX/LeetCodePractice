class Solution {
public:
    /*
    1st and brute force approach can be lets for all ch:s delete s from string
    and call is palindrome if any one is true return true
    one two approach be lets call check for only when s[i]*!=s[j]*/
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (j > i) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(s.substr(0, i) + s.substr(i + 1)) ||
                       isPalindrome(s.substr(0, j) + s.substr(j + 1));
            }
            j--, i++;
        }
        return true;
    }
};