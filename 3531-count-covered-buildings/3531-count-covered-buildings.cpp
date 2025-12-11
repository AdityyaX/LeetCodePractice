class Solution {
public:
    /*
    here intution can be for every x storty {min and max}y in a map and same for
    every y then again run and check for every building if x and y is less than
    min and max then count++*/

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> foreveryXminAndMaxY;
        unordered_map<int, pair<int, int>> foreveryYminAndMaxX;
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if (!foreveryXminAndMaxY.count(x)) {
                foreveryXminAndMaxY[x] = {INT_MAX, INT_MIN};
            }
            if (!foreveryYminAndMaxX.count(y)) {
                foreveryYminAndMaxX[y] = {INT_MAX, INT_MIN};
            }
            foreveryXminAndMaxY[x].first = min(foreveryXminAndMaxY[x].first, y);
            foreveryXminAndMaxY[x].second =
                max(foreveryXminAndMaxY[x].second, y);

            foreveryYminAndMaxX[y].first = min(foreveryYminAndMaxX[y].first, x);
            foreveryYminAndMaxX[y].second =
                max(foreveryYminAndMaxX[y].second, x);
        }
        int result = 0;
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            bool insideX = (y > foreveryXminAndMaxY[x].first &&
                            y < foreveryXminAndMaxY[x].second);

            bool insideY = (x > foreveryYminAndMaxX[y].first &&
                            x < foreveryYminAndMaxX[y].second);

            if (insideX && insideY)
                result++;
        }
        return result;
    }
};