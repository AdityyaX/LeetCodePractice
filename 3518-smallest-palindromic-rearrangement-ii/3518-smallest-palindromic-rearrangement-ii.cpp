class Solution {
public:
    const long long LIM = 1000001;

    long long nCr(int n, int r) {
        r = min(r, n - r);
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long res = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            res *= nCr(rem, x);
            if (res >= LIM) return LIM;
            rem -= x;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        int len = s.size() / 2;
        string left;

        while ((int)left.size() < len) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};