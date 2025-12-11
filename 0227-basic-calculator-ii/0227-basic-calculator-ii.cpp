class Solution {
public:
    int calculate(string s) {
        int number = 0;
        char sign = '+';
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            char currentCh = s[i];
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }

            if ((!isdigit(currentCh) && !isspace(currentCh)) ||
                i == s.size() - 1) {
                if (sign == '+') {
                    st.push(number);
                } else if (sign == '-') {
                    st.push(-number);
                } else if (sign == '*') {
                    int topVal = st.top();
                    st.pop();
                    st.push(topVal * number);
                } else if (sign == '/') {
                    int topVal = st.top();
                    st.pop();
                    st.push(topVal / number);
                }

                sign = currentCh;
                number = 0;
            }
        }

        int num = 0;
        while (!st.empty()) {
            int val = st.top();
            st.pop();
            num += val;
        }
        return num;
    }
};