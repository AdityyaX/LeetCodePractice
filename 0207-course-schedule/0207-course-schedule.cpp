class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adjLs, vector<int>& visited,
             vector<int>& inStack) {
        inStack[i] = 1;
        visited[i] = 1;
        for (int nei : adjLs[i]) {
            if (!visited[nei]) {
                if (dfs(nei, adjLs, visited, inStack))
                    return true;
            } else if (inStack[nei]) {
                return true;
            }
        }
        inStack[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        for (auto& e : prerequisites) {
            int course = e[0];
            int prereq = e[1];
            adjLs[prereq].push_back(course);
        }
        vector<int> inStack(numCourses);
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adjLs, visited, inStack)) {
                    return false;
                }
            }
        }
        return true;
    }
};