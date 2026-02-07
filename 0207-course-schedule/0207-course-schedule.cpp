class Solution {
public:
    bool dfs(vector<vector<int>>& adjLs, vector<int>& visited, int i) {
        visited[i] = 1;
        for (auto nei : adjLs[i]) {
            if (visited[nei] == 0) {
                if (dfs(adjLs, visited, nei))
                    return true;
            } else if (visited[nei] == 1) {
                return true;
            }
        }
        visited[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adjLs(numCourses);
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjLs[v].push_back(u);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adjLs, visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};