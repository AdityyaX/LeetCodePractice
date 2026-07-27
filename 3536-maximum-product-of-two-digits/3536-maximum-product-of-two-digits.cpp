class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n) {
            int digit = n % 10;
            digits.push_back(digit);
            cout << digit << endl;
            n = n / 10;
        }
        sort(digits.begin(), digits.end());
        return digits[digits.size() - 1] * digits[digits.size() - 2];
    }
};