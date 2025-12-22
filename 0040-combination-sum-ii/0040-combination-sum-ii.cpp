class Solution {
private:
    vector<vector<int>> result;

public:
    void helper(int start, vector<int>& candidates, int target,
                vector<int>& subArray) {
        if (target == 0) {
            result.push_back(subArray);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            subArray.push_back(candidates[i]);
            helper(i + 1, candidates, target - candidates[i], subArray);
            subArray.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subArray;
        helper(0, candidates, target, subArray);
        return result;
    }
};
