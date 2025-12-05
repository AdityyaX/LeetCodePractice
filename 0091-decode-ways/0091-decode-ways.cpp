class Solution {
public:
    /*
    1st thing dp[n] represents number of way to represent number till that digit
    transiiton fn if (it is valid for 1 then sum it with dp [i-1]) else dp[i-1]
    base is dp[i]=='0' return or string is empty
    */
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};