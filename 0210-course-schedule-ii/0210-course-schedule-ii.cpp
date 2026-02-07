class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        int count = 0;
        vector<int> visited(numCourses, 0);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adjLs[y].push_back(x);
            inDegree[x]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            count++;
            result.push_back(n);
            for (int node : adjLs[n]) {
                if (--inDegree[node] == 0) {
                    q.push(node);
                }
            }
        }
        if (count == numCourses) {
            return result;
        }
        return {};
    }
};