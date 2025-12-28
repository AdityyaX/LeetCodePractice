class Solution {
public:
    void dfs(vector<vector<int>> adjLs, vector<bool>& visited, int i) {
        visited[i] = true;
        for (auto neighbour : adjLs[i]) {
            if (!visited[neighbour]) {
                dfs(adjLs, visited, neighbour);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adjLs(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adjLs, visited, i);
                count++;
            }
        }
        return count;
    }
};