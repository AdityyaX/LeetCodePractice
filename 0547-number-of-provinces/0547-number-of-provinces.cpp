class Solution {
public:
    void dfs(int i, vector<int>& visted, vector<vector<int>>& adjLs) {
        visted[i] = 1;
        for (auto& it : adjLs[i]) {
            if (!visted[it]) {
                dfs(it, visted, adjLs);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numberComponents = 0;
        int n = isConnected.size();
        vector<int> visted(n, 0);
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
            if (!visted[i]) {
                dfs(i, visted, adjLs);
                numberComponents++;
            }
        }
        return numberComponents;
    }
};