class Solution {
public:
    /*
    here we sort with the difference beween city proce and then send 1st n/2 to
    and and last n/2 to b for negative a is cheaper for positive b is cheaper*/
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });

        int n = costs.size();
        int total = 0;

        for (int i = 0; i < n / 2; i++) {
            total += costs[i][0];
            total += costs[i + n / 2][1];
        }

        return total;
    }
};