class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        for (char c : tasks) {
            maxFreq = max(maxFreq, freq[c - 'A']);
        }
        int count = 0;
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
    }
};