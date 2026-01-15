class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int countHbars = 1;
        int maxHbars = 1;
        int countVbars = 1;
        int maxVbars = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                countHbars++;
                maxHbars = max(maxHbars, countHbars);
            } else {
                countHbars = 1;
            }
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                countVbars++;
                maxVbars = max(maxVbars, countVbars);
            } else {
                countVbars = 1;
            }
        }

        int minVal = min(maxHbars, maxVbars) + 1;

        return minVal * minVal;
    }
};