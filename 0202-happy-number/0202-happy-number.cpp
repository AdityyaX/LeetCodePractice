class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> seen;

        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
            if (n == 0) {
                if (sum == 1) {
                    return true;
                }
                if (seen.count(sum))
                    return false;
                seen.insert(sum);
                n = sum;
                sum = 0;
            }
        }
        return false;
    }
};