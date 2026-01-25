class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;
                char topElement = st.top();
                st.pop();
                if (ch == ')' && topElement != '(' ||
                    ch == '}' && topElement != '{' ||
                    ch == ']' && topElement != '[')
                    return false;
            }
        }
        return st.empty();
    }
};