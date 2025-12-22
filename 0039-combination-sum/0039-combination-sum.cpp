class Solution {
private:
    vector<vector<int>> result;

public:
    void helper(int i, vector<int>& candidates, int target,
                vector<int> subArray) {
        if (target == 0) {
            result.push_back(subArray);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }

        subArray.push_back(candidates[i]);
        helper(i, candidates, target - candidates[i], subArray);
        subArray.pop_back();
        helper(i + 1, candidates, target, subArray);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subArray;
        helper(0, candidates, target, subArray);
        return result;
    }
};