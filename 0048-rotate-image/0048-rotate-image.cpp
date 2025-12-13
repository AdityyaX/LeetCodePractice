class Solution {
public:
    /*
    this one is brute force approach fid the pattern inside the value
    optimal approach:
    reverse the whole matrix vertically
    and then return transpose of the matrix
    in optimal approach we have same on^2 time but space is o(1)
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};