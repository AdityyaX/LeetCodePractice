class Solution {
public:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& adjLs) {
        visited[i] = 1;
        for (int nei : adjLs[i]) {
            if (!visited[nei]) {
                dfs(nei, visited, adjLs);
            }
        }
    }
    /*
    universal pattern for this problem is let's make a */
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adjLs(n);
        int connectedComponent = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adjLs);
                connectedComponent++;
            }
        }
        return connectedComponent - 1;
    }
};