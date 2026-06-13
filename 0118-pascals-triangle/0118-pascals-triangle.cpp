class Solution {
public:
    void helper(vector<vector<int>>& result, int N) {
        int value = 1;
        vector<int> rows;
        rows.push_back(1);
        for (int i = 1; i <= N; i++) {
            value = value * (N - i + 1) / i;
            rows.push_back(value);
        }
        result.push_back(rows);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            helper(result, i);
        }
        return result;
    }
};