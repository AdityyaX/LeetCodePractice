class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i = 0;
        string result;
        int zeroes = 0;
        int ones = 0;
        int total = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                zeroes++;
            }
            if (s[j] == '1') {
                ones++;
            }
            while (zeroes > k && ones > k) {
                if (s[i] == '0')
                    zeroes--;
                else
                    ones--;
                i++;
            }
            total += (j - i + 1);
        }
        return total;
    }
};