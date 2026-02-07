class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> coloured(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (coloured[i] != -1)
                continue;
            q.push(i);
            coloured[i] = 0;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int node : graph[x]) {
                    if (coloured[node] == -1) {
                        q.push(node);
                        coloured[node] = !coloured[x];

                    } else if (coloured[x] == coloured[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};