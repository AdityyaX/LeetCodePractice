class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (islower(ch)) {
                result += ch;
            }
            if (ch == '*') {
                if (!result.empty())
                    result.pop_back();
            }
            if (ch == '#') {
                result.append(result);
            }
            if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};