class Solution {
    /*
    here we have same approach as longest palindromic substring 
    just return number of i in dp array
    */
public:
    int countSubstrings(string s) {
        int maxLen = 0, start = 0;
        int num = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1] == 1)) {
                    dp[i][j] = 1;
                    num++;
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return num;
    }
};