class Solution {
public:
/*
so here dp[][]represent is string [i][j] is palindrome or not

*/
    string longestPalindrome(string s) {
        int maxLen = 0, start = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1] == 1)) {
                    dp[i][j] = 1;
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};