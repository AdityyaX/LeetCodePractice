class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<bool>& visited, int& nodes,
             int& edge, int node) {
        visited[node] = true;
        nodes++;
        edge += edges[node].size();
        for (auto& rei : edges[node]) {
            if (!visited[rei]) {
                dfs(edges, visited, nodes, edge, rei);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            int counntNode = 0;
            int countEdge = 0;
            if (!visited[i]) {
                dfs(adj, visited, counntNode, countEdge, i);
                countEdge /= 2;
                if (countEdge == counntNode * (counntNode - 1) / 2) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};