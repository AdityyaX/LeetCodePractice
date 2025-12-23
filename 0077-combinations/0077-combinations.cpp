class Solution {
public:
    vector<vector<int>> result;
    void helper(int i, int n, int k, vector<int>& current) {

        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        if (i == n)
            return;
        current.push_back(i + 1);
        helper(i + 1, n, k, current);
        current.pop_back();
        helper(i + 1, n, k, current);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        helper(0, n, k, current);
        return result;
    }
};