class Solution {
public:
    void dfs(vector<vector<int>>& adjLs, vector<int>& visited, int& nodes,
             int& edges, int i) {
        visited[i] = 1;
        nodes++;
        edges += adjLs[i].size();
        for (int nei : adjLs[i]) {
            if (!visited[nei]) {
                dfs(adjLs, visited, nodes, edges, nei);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLs(n);
        vector<int> visited(n, 0);
        int countComonents = 0;
        for (auto& e : edges) {
            adjLs[e[0]].push_back(e[1]);
            adjLs[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edges = 0;
                dfs(adjLs, visited, nodes, edges, i);
                edges /= 2;
                if (edges == nodes * (nodes - 1) / 2) {
                    countComonents++;
                }
            }
        }
        return countComonents;
    }
};