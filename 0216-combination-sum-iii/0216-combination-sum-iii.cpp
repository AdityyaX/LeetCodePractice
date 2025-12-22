class Solution {
private:
    vector<vector<int>> result;

public:
    void helper(int start, int k, int target, vector<int>& subArray) {
        if (k == 0 && target == 0) {
            result.push_back(subArray);
            return;
        }
        if (k == 0 || target < 0)
            return;

        for (int ind = start; ind <= 9; ind++) {
            subArray.push_back(ind);
            helper(ind + 1, k - 1, target - ind, subArray);
            subArray.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subArray;
        helper(1, k, n, subArray);
        return result;
    }
};