class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (auto str : words) {
            int ans = 0;
            for (char c : str) {
                ans += weights[c - 'a'];
            }
            result += char('a' + 25 - (ans % 26));
        }
        return result;
    }
};