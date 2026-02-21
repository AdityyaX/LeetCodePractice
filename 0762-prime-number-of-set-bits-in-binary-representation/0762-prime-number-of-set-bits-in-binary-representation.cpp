class Solution {
public:
    bool helper(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 ||
                x == 17 || x == 19);
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (helper(__builtin_popcount(i))) {
                ans++;
            }
        }
        return ans;
    }
};