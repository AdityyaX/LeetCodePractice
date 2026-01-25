class Solution {
public:
    // n = n & (n - 1) removes right most 1 bit from the number;
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};