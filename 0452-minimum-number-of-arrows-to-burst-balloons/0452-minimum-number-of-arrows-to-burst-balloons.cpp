class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int count = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (end < points[i][0]) {
                count++;
                cout << end << endl << points[i][1] << endl;
                end = points[i][1];
            }
        }
        return count;
    }
};