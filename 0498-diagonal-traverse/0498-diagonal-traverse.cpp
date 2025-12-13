class Solution {
public:
    /*
    here i got the approach i should follow but gort confiused with why taking n
    in innner loop because highest value we can have for i is n amd also the
    reverse thing is importantt*/
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> result;
        int m = mat[0].size();
        int len = n + m - 1;
        for (int d = 0; d < len; d++) {
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                int j = d - i;
                if (j >= 0 && j < m) {
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