class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mpp;
        vector<int> result;
        for (auto it : grid) {
            for (auto num : it) {
                mpp[num]++;
            }
        }
        for (auto mp : mpp) {
            if (mp.second == 2) {
                result.push_back(mp.first);
            }
        }
        int n = grid.size();
        for (int i = 1; i <= n * n; i++) {
            if (mpp[i] == 0) {
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};