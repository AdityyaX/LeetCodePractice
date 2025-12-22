class Solution {
public:
    bool dfs(int idx, vector<int>& matchsticks, vector<int>& sides,
             int target) {
        if (idx == matchsticks.size())
            return true;

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] > target)
                continue;
            if (i > 0 && sides[i] == sides[i - 1])
                continue;

            sides[i] += matchsticks[idx];
            if (dfs(idx + 1, matchsticks, sides, target))
                return true;
            sides[i] -= matchsticks[idx];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        sort(matchsticks.rbegin(), matchsticks.rend());
        int target = sum / 4;

        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);
        return dfs(0, matchsticks, sides, target);
    }
};
