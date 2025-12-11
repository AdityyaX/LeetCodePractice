class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        long long result = 0;
        int sign = 1;
        stack<long long> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');

            } else if (s[i] == '+') {
                result += (number * sign);
                number = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += (number * sign);
                number = 0;
                sign = -1;

            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                number = 0;
                result = 0;
                sign = 1;

            } else if (s[i] == ')') {
                result += number * sign;
                number = 0;
                int topValueSign = st.top();
                st.pop();
                int topValue = st.top();
                st.pop();
                result = result * topValueSign;
                result += topValue;
            }
        }
        return result + sign * number;
    }
};