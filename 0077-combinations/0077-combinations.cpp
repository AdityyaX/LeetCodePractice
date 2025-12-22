class Solution {
public:
    vector<vector<int>> result;
    void helper(int i, int k, vector<int>& combination, int n) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
        if (i == n)
            return;
        combination.push_back(i + 1);
        helper(i + 1, k, combination, n);
        combination.pop_back();
        helper(i + 1, k, combination, n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        helper(0, k, combination, n);
        return result;
    }
};