class Solution {
public:
    // where ever we are sorting and using two pointer then it is greedy here we
    // first sort both array and then check for where fot all j i satisfy greed
    // or not if it satisfy then count++ else we do j++
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};