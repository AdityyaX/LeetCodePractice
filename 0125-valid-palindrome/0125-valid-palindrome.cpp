class Solution {
    /*
    here brute force can be add the string in a new temp string avoid spaces
    and the compare new string with it reverse we can use rbegin,rend function
  */
public:
    bool isPalindromeHelper(int i, string& s) {
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int i = 0;
        return isPalindromeHelper(i, s);
    }
};