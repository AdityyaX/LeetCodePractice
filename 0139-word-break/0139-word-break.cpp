class Solution {
public:
    bool dfs(string s, vector<string>& wordDict, vector<int>& dp, int start) {
        if (start == s.size())
            return true;
        if (dp[start] != -1)
            return dp[start];

        for (auto& word : wordDict) {
            int len = word.size();
            if (start + len <= s.size() && s.substr(start, len) == word) {
                if (dfs(s, wordDict, dp, start + len)) {
                    return dp[start] = true;
                }
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        int start = 0;
        return dfs(s, wordDict, dp, start);
    }
};