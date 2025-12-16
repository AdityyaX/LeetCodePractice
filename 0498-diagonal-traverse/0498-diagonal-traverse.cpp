class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(); // rows
        int n = mat[0].size();
        vector<int> result;
        int len = n + m - 1;
        for (int d = 0; d < len; d++) {
            vector<int> temp;
            for (int i = 0; i < m; i++) {
                int j = d - i;
                if (j >= 0 && j < n) {
                    temp.push_back(mat[i][j]);
                }
            }
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};