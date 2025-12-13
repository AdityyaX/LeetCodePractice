class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int index = 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {

                matrix[top][i] = index;
                index++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                int square = index;
                matrix[i][right] = index;
                index++;
            }
            right--;
            if (bottom >= top) {

                for (int i = right; i >= left; i--) {
                    int square = index;
                    matrix[bottom][i] = index;
                    index++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    int square = index;
                    matrix[i][left] = square;
                    index++;
                }
                left++;
            }
        }
        return matrix;
    }
};