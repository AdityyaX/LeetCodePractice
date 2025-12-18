class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top() - i;
            } else {
                result[i] = 0;
            }
            st.push(i);
        }
        return result;
    }
};