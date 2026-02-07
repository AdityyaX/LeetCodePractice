class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        int count = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            indegree[x]++;
            adj[y].push_back(x);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {

            int node = q.front();
            q.pop();
            count++;
            for (int x : adj[node]) {
                if (--indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        return count == numCourses;
    }
};