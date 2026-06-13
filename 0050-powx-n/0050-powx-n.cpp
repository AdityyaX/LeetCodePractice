class Solution {
public:
    // 2^10 4^5 4*4^4 16^2 256^1*2 1024

    double myPow(double x, int n) {
        long long nn = n;
        if (nn < 0)
            nn = -nn;
        double ans = 1.0;
        while (nn > 0) {
            if (nn & 1) {
                ans = ans * x;
                cout << ans << endl;
            }

            x *= x;
            nn >>= 1;
        }
        return n < 0 ? 1 / ans : ans;
    }
};