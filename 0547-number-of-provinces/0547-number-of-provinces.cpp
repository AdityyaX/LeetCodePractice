class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& isVisited) {
        isVisited[node] = 1;
        for (auto adj : adjLs[node]) {
            if (!isVisited[adj]) {
                dfs(adj, adjLs, isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> isVisited(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!isVisited[i]) {
                cnt++;
                dfs(i, adjLs, isVisited);
            }
        }
        return cnt;
    }
};