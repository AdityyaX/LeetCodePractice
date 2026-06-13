class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> value(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        value[i][k] = -1;
                    }
                    for (int p = 0; p < m; p++) {
                        value[p][j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (value[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};