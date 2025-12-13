class Solution {
public:
    /*
    this one is brute force approach fid the pattern inside the value*/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[i][j] = matrix[n - j - 1][i];
            }
        }

        matrix = rotated;
    }
};