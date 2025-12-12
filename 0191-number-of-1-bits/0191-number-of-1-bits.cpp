class Solution {
public:
    // n = n & (n - 1) removes right most bit from the number;
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};